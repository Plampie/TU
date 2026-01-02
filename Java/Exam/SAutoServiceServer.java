import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Главен клас – стартира многонишковия сървър на порт 5678.
 * За всеки клиент създава нов ClientHandler (Thread).
 */
public class AutoServiceServer {

    private static final int PORT = 5678;

    private final ServiceCenter serviceCenter = new ServiceCenter();

    public static void main(String[] args) {
        AutoServiceServer server = new AutoServiceServer();
        server.start();
    }

    public void start() {
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("AutoServiceServer started on port " + PORT);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                ClientHandler handler = new ClientHandler(clientSocket, serviceCenter);
                handler.start(); // нова нишка за всеки клиент
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.Socket;
import java.util.List;

/**
 * Обслужва един клиент в отделна нишка.
 *
 * Протокол (примерен):
 *
 * Команда 1 – регистриране на нова поръчка:
 *   client -> server:
 *     int 1
 *     UTF carRegNumber
 *     UTF description
 *
 *   server -> client:
 *     boolean success
 *     int id (или -1 при грешка)
 *     UTF message
 *
 * Команда 2 – промяна на статус:
 *   client -> server:
 *     int 2
 *     int id
 *     UTF newStatus
 *
 *   server -> client:
 *     boolean success
 *     UTF message
 *
 * Команда 3 – справка по статус:
 *   client -> server:
 *     int 3
 *     UTF status
 *
 *   server -> client:
 *     int count
 *     (повтаря се count пъти)
 *        int id
 *        UTF carRegNumber
 *        UTF description
 *        UTF status
 *
 * Друга стойност за команда или EOF -> затваряне на връзката.
 */
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
                    // клиентът е затворил връзката
                    break;
                }

                if (command == 1) {
                    handleRegisterOrder(in, out);
                } else if (command == 2) {
                    handleChangeStatus(in, out);
                } else if (command == 3) {
                    handleListByStatus(in, out);
                } else {
                    // непозната команда или сигнал за край – спираме
                    break;
                }
            }

        } catch (IOException e) {
            System.out.println("Error with client " + socket.getRemoteSocketAddress()
                    + ": " + e.getMessage());
        } finally {
            System.out.println("Client disconnected: " + socket.getRemoteSocketAddress());
        }
    }

    /**
     * TODO 4:
     * Обработка на команда 1 – регистриране на нова поръчка.
     *
     * Вход (от клиента):
     *   UTF carRegNumber
     *   UTF description
     *
     * Логика:
     *   - извикване на serviceCenter.registerOrder(...)
     *   - връщане към клиента:
     *       boolean success (true)
     *       int id (генерираното id)
     *       UTF message
     *
     * По желание: може да се добави проверка за вече активна поръчка.
     */
    private void handleRegisterOrder(DataInputStream in, DataOutputStream out) throws IOException {
        throw new UnsupportedOperationException("TODO 4: имплементирайте handleRegisterOrder");
    }

    /**
     * TODO 5:
     * Обработка на команда 2 – смяна на статус.
     *
     * Вход (от клиента):
     *   int id
     *   UTF newStatus
     *
     * Логика:
     *   - извикване на serviceCenter.changeStatus(id, newStatus)
     *   - връщане:
     *       boolean success
     *       UTF message (например 'OK' или 'Няма поръчка с такова ID')
     */
    private void handleChangeStatus(DataInputStream in, DataOutputStream out) throws IOException {
        throw new UnsupportedOperationException("TODO 5: имплементирайте handleChangeStatus");
    }

    /**
     * TODO 6:
     * Обработка на команда 3 – справка по статус.
     *
     * Вход (от клиента):
     *   UTF status
     *
     * Логика:
     *   - извикване на serviceCenter.getOrdersByStatus(status)
     *   - връщане към клиента:
     *       int count
     *       повторение count пъти:
     *          int id
     *          UTF carRegNumber
     *          UTF description
     *          UTF status
     */
    private void handleListByStatus(DataInputStream in, DataOutputStream out) throws IOException {
        throw new UnsupportedOperationException("TODO 6: имплементирайте handleListByStatus");
    }
}


public class RepairOrder {

    private final int id;
    private final String carRegNumber;
    private final String description;
    private String status; // например "NEW", "IN_PROGRESS", "DONE"

    public RepairOrder(int id, String carRegNumber, String description, String status) {
        this.id = id;
        this.carRegNumber = carRegNumber;
        this.description = description;
        this.status = status;
    }

    public int getId() {
        return id;
    }

    public String getCarRegNumber() {
        return carRegNumber;
    }

    public String getDescription() {
        return description;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "RepairOrder{" +
                "id=" + id +
                ", carRegNumber='" + carRegNumber + '\'' +
                ", description='" + description + '\'' +
                ", status='" + status + '\'' +
                '}';
    }
}



import java.util.ArrayList;
import java.util.List;

/**
 * Споделен обект, който държи всички поръчки.
 * Тук се очаква използване на synchronized.
 */
public class ServiceCenter {

    private final List<RepairOrder> orders = new ArrayList<>();
    private int nextId = 1;

    /**
     * TODO 1:
     * Регистрира нова поръчка със статус "NEW" и връща генерираното id.
     *
     * Примерна логика:
     *   - вземи текущото nextId и го запази в локална променлива id
     *   - увеличи nextId
     *   - създай нов RepairOrder(id, carRegNumber, description, "NEW")
     *   - добави го в списъка orders
     *   - върни id
     *
     * Методът трябва да е synchronized, за да е безопасен при много нишки.
     */
    public synchronized int registerOrder(String carRegNumber, String description) {
        throw new UnsupportedOperationException("TODO 1: имплементирайте registerOrder");
    }

    /**
     * TODO 2:
     * Променя статуса на поръчка с дадено id на newStatus.
     * Връща true при успех, false ако няма такава поръчка.
     *
     * Примерна логика:
     *   - обхождане на orders
     *   - ако order.getId() == id:
     *       order.setStatus(newStatus);
     *       return true;
     *   - в края: return false;
     *
     * Методът трябва да е synchronized.
     */
    public synchronized boolean changeStatus(int id, String newStatus) {
        throw new UnsupportedOperationException("TODO 2: имплементирайте changeStatus");
    }

    /**
     * TODO 3:
     * Връща НОВ списък с всички поръчки със статус, равен на подадения (case-insensitive).
     *
     * Примерна логика:
     *   List<RepairOrder> result = new ArrayList<>();
     *   за всяка order в orders:
     *       ако order.getStatus().equalsIgnoreCase(status):
     *           добави в result
     *   върни result
     *
     * Методът трябва да е synchronized.
     */
    public synchronized List<RepairOrder> getOrdersByStatus(String status) {
        throw new UnsupportedOperationException("TODO 3: имплементирайте getOrdersByStatus");
    }

    /**
     * НЕ е задължително за условието, но помага за проверка.
     * По избор може да се имплементира от студента.
     */
    public synchronized List<RepairOrder> getAllOrders() {
        return new ArrayList<>(orders);
    }
}
