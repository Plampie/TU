import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.Socket;
import java.util.List;

public class ClientHandler extends Thread {

    private final Socket socket;
    private final ServiceCenter serviceCenter;

    public ClientHandler(Socket socket, ServiceCenter serviceCenter) {
        this.socket = socket;
        this.serviceCenter = serviceCenter;
    }

    @Override
    public void run() {
        System.out.println("Client connected: " + socket.getRemoteSocketAddress());
        try (Socket s = socket;
             DataInputStream in = new DataInputStream(s.getInputStream());
             DataOutputStream out = new DataOutputStream(s.getOutputStream())) {

            while (true) {
                int command;
                try {
                    command = in.readInt();
                } catch (EOFException eof) {
                    break;
                }

                if (command == 1) {
                    handleRegisterOrder(in, out);
                } else if (command == 2) {
                    handleChangeStatus(in, out);
                } else if (command == 3) {
                    handleListByStatus(in, out);
                } else {
                    break;
                }
            }

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Client disconnected.");
        }
    }

    // Command 1 - Register 
    private void handleRegisterOrder(DataInputStream in, DataOutputStream out) throws IOException {
        String carReg = in.readUTF();
        String desc = in.readUTF();

        int id = serviceCenter.registerOrder(carReg, desc); 

        if (id != -1) {
            out.writeBoolean(true);
            out.writeInt(id);
            out.writeUTF("Order created successfully.");
        } else {
            out.writeBoolean(false);
            out.writeInt(-1);
            out.writeUTF("Active order already exists for this car."); 
        }
        out.flush();
    }

    // Command 2 - Change Status [cite: 11]
    private void handleChangeStatus(DataInputStream in, DataOutputStream out) throws IOException {
        int id = in.readInt();
        String newStatus = in.readUTF();

        boolean success = serviceCenter.changeStatus(id, newStatus);

        out.writeBoolean(success);
        out.writeUTF(success ? "Status updated to " + newStatus : "Order ID not found");
        out.flush();
    }

    // Command 3 - List by Status
    private void handleListByStatus(DataInputStream in, DataOutputStream out) throws IOException {
        String status = in.readUTF();
        List<RepairOrder> orders = serviceCenter.getOrdersByStatus(status);

        out.writeInt(orders.size());
        
        for (RepairOrder o : orders) {
            out.writeInt(o.getId());
            out.writeUTF(o.getCarRegNumber());
            out.writeUTF(o.getDescription());
            out.writeUTF(o.getStatus());
        }
        out.flush();
    }
}