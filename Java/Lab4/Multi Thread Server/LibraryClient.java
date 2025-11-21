import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class LibraryClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 5000)) {
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            Scanner scanner = new Scanner(System.in);

            System.out.println("Connected to library server.");

            while (true) {
                System.out.println("\nChoose operation:");
                System.out.println("1 - Add book");
                System.out.println("2 - Rent book");
                System.out.println("3 - Return book");
                System.out.println("0 - Exit client");

                int choice;
                try {
                    choice = Integer.parseInt(scanner.nextLine());
                } catch (NumberFormatException e) {
                    System.out.println("Invalid number.");
                    continue;
                }

                if (choice == 0) {
                    System.out.println("Exiting client...");
                    break;
                } else if (choice == 1) {
                    System.out.println("Enter title:");
                    String title = scanner.nextLine();
                    System.out.println("Enter author:");
                    String author = scanner.nextLine();

                    out.writeInt(1);
                    out.writeUTF(title);
                    out.writeUTF(author);
                    out.flush();

                    System.out.println("Server: " + in.readUTF());

                } else if (choice == 2) {
                    System.out.println("Enter book id:");
                    int id;
                    try {
                        id = Integer.parseInt(scanner.nextLine());
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid id.");
                        continue;
                    }
                    System.out.println("Enter your name:");
                    String user = scanner.nextLine();

                    out.writeInt(2);
                    out.writeInt(id);
                    out.writeUTF(user);
                    out.flush();

                    System.out.println("Server: " + in.readUTF());

                } else if (choice == 3) {
                    System.out.println("Enter book id:");
                    int id;
                    try {
                        id = Integer.parseInt(scanner.nextLine());
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid id.");
                        continue;
                    }

                    out.writeInt(3);
                    out.writeInt(id);
                    out.flush();

                    System.out.println("Server: " + in.readUTF());

                } else {
                    System.out.println("Unknown option.");
                }
            }
        } catch (IOException e) {
            System.out.println("Client error: " + e.getMessage());
        }
    }
}
