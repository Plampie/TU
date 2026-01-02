import java.io.*;
import java.net.*;
import java.util.*;

public class AutoServiceServer {

    private static final int PORT = 5678;
    private static final ServiceCenter serviceCenter = new ServiceCenter();

    public static void main(String[] args) {
        System.out.println("Server started on port " + PORT);

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getRemoteSocketAddress());

                ClientHandler handler = new ClientHandler(clientSocket, serviceCenter);
                handler.start();
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }


    static class ClientHandler extends Thread {
        private final Socket socket;
        private final ServiceCenter serviceCenter;

        @Override
        public void run() {
            try (
                DataInputStream in = new DataInputStream(socket.getInputStream());
                DataOutputStream out = new DataOutputStream(socket.getOutputStream())
            ) {
                while (true) {
                    int command;
                    try {
                        command = in.readInt();
                    } catch (EOFException e) {
                        break;
                    }

                    if (command == 1) {
                        String regNum = in.readUTF();
                        String desc = in.readUTF();

                        int newId = serviceCenter.registerOrder(regNum, desc);

                        if (newId != -1) {
                            out.writeBoolean(true);
                            out.writeInt(newId);
                            out.writeUTF("Order registered successfully.");
                        } else {
                            out.writeBoolean(false);
                            out.writeInt(-1);
                            out.writeUTF("Error: Active order already exists.");
                        }
                        out.flush();

                    } else if (command == 2) {
                        int id = in.readInt();
                        String newStatus = in.readUTF();

                        boolean success = serviceCenter.changeStatus(id, newStatus);

                        out.writeBoolean(success);
                        if (success) {
                            out.writeUTF("Status changed to " + newStatus);
                        } else {
                            out.writeUTF("Error: Order ID not found.");
                        }
                        out.flush();

                    } else if (command == 3) {
                        String statusToCheck = in.readUTF();
                        List<RepairOrder> found = serviceCenter.getOrdersByStatus(statusToCheck);

                        out.writeInt(found.size());
                        for (RepairOrder o : found) {
                            out.writeInt(o.id);
                            out.writeUTF(o.carRegNumber);
                            out.writeUTF(o.description);
                            out.writeUTF(o.status);
                        }
                        out.flush();

                    } else {
                        break;
                    }
                }
            } catch (IOException e) {
                System.out.println("Error with client: " + e.getMessage());
            } finally {
                System.out.println("Client disconnected.");
                try {
                    socket.close();
                } catch (IOException ignored) {}
            }
        }
    }


    static class ServiceCenter {
        private final List<RepairOrder> orders = new ArrayList<>();
        private int nextId = 1;

        public synchronized int registerOrder(String carRegNumber, String description) {
            for (RepairOrder o : orders) {
                if (o.carRegNumber.equalsIgnoreCase(carRegNumber) &&
                    (o.status.equals("NEW") || o.status.equals("IN_PROGRESS"))) {
                    return -1;
                }
            }

            RepairOrder order = new RepairOrder();
            order.id = nextId++;
            order.carRegNumber = carRegNumber;
            order.description = description;
            order.status = "NEW";

            orders.add(order);
            return order.id;
        }

        public synchronized boolean changeStatus(int id, String newStatus) {
            for (RepairOrder o : orders) {
                if (o.id == id) {
                    o.status = newStatus;
                    return true;
                }
            }
            return false;
        }

        public synchronized List<RepairOrder> getOrdersByStatus(String status) {
            List<RepairOrder> result = new ArrayList<>();
            for (RepairOrder o : orders) {
                if (o.status.equalsIgnoreCase(status)) {
                    result.add(o);
                }
            }
            return result;
        }
    }

    
    static class RepairOrder {
        public int id;
        public String carRegNumber;
        public String description;
        public String status;
    }
}
