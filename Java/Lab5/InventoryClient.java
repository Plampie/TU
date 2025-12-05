import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class InventoryClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 8080);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
             Scanner scanner = new Scanner(System.in)) {

            while (true) {
                String input = scanner.nextLine();
                out.write(input);
                out.newLine();

                if (input.equals("STATUS_BY_DATE")) {
                    String date = scanner.nextLine();
                    out.write(date);
                    out.newLine();
                }

                out.flush();

                String line;
                while ((line = in.readLine()) != null) {
                    System.out.println(line);
                    if (line.startsWith("OUT_OF_WARRANTY:") || line.equals("UNKNOWN_COMMAND"))
                        break;
                }

                if (input.equals("QUIT")) break;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}