import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.Socket;

public class ClientHandler implements Runnable { // it can be run inside a Thread
    private Socket socket; // TCP connection
    private Library library; // shared library instance

    public ClientHandler(Socket socket, Library library) {
        this.socket = socket;
        this.library = library;
    }

    @Override
    public void run() {
        try (Socket s = socket) {
            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());

            // handle commands until client disconnects
            while (true) {
                
                int opCode;

                try {
                    opCode = in.readInt();
                } catch (EOFException e) {
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
                    out.writeUTF("Unknown operation code: " + opCode);
                    out.flush();
                }
            }
        } catch (IOException e) {
            System.out.println("Error while handling client: " + e.getMessage());
        }
    }
}
