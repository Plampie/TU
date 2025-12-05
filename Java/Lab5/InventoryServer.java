import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class InventoryServer {
    public static final int PORT = 8080;
    public static List<Product> products = Collections.synchronizedList(new ArrayList<>());

    public static void main(String[] args) {
        populateInitialData();

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server running on port " + PORT);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                new ClientHandler(clientSocket, products).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void populateInitialData() {
        products.add(new FoodProduct(1, "Milk", 10, 2.99, LocalDate.now().plusDays(2)));
        products.add(new FoodProduct(2, "Cheese", 5, 4.49, LocalDate.now().minusDays(1)));
        products.add(new NonFoodProduct(3, "Toaster", 2, 25.0, LocalDate.now().plusMonths(6)));
        products.add(new NonFoodProduct(4, "TV", 1, 499.99, LocalDate.now().minusMonths(2)));
    }
}
