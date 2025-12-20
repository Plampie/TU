import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class AutoServiceServer {

    private static final int PORT = 5678; 
    private final ServiceCenter serviceCenter = new ServiceCenter();

    public static void main(String[] args) {
        new AutoServiceServer().start();
    }

    public void start() {
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                new ClientHandler(clientSocket, serviceCenter).start();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}