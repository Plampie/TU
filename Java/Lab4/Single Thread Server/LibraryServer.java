import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
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
                try (Socket clientSocket = serverSocket.accept()) {
                    System.out.println("Client connected.");

                    DataInputStream in = new DataInputStream(clientSocket.getInputStream());
                    DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());

                    while (true) {
                        int opCode;
                        try {
                            opCode = in.readInt();
                        } catch (EOFException e) {
                            System.out.println("Client disconnected.");
                            break;
                        }

                        if (opCode == 1) {
                            String title = in.readUTF();
                            String author = in.readUTF();
                            String result = library.addBook(title, author);
                            out.writeUTF(result);
                            out.flush();
                        } else if (opCode == 2) {
                            int id = in.readInt();
                            String user = in.readUTF();
                            String result = library.rentBook(id, user);
                            out.writeUTF(result);
                            out.flush();
                        } else if (opCode == 3) {
                            int id = in.readInt();
                            String result = library.returnBook(id);
                            out.writeUTF(result);
                            out.flush();
                        } else {
                            String result = "Unknown operation code: " + opCode;
                            out.writeUTF(result);
                            out.flush();
                        }
                    }
                } catch (IOException e) {
                    System.out.println("Error while handling client: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }
}
