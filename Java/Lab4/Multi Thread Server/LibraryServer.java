import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class LibraryServer {
    public static void main(String[] args) {
        Library library = new Library();

        try (ServerSocket serverSocket = new ServerSocket(5000)) {
            System.out.println("Library server started on port 5000.");

            while (true) {
                System.out.println("Waiting for client...");
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());

                ClientHandler handler = new ClientHandler(clientSocket, library);
                Thread t = new Thread(handler);
                t.start();
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }
}
