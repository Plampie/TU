import java.io.*;
import java.net.Socket;
import java.time.LocalDate;
import java.util.List;

public class ClientHandler extends Thread {
    private Socket socket;
    private List<Product> products;

    public ClientHandler(Socket socket, List<Product> products) {
        this.socket = socket;
        this.products = products;
    }

    @Override
    public void run() {
        try (
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        ) {
            String command;
            while ((command = in.readLine()) != null) {
                switch (command) {
                    case "LIST_ALL":
                        handleListAll(out);
                        break;
                    case "STATUS_BY_DATE":
                        String dateLine = in.readLine();
                        handleStatusByDate(out, LocalDate.parse(dateLine));
                        break;
                    case "QUIT":
                        socket.close();
                        return;
                    default:
                        out.write("UNKNOWN_COMMAND\n");
                        out.flush();
                }
            }
        } catch (IOException e) {
            System.out.println("Client disconnected.");
        }
    }

    private void handleListAll(BufferedWriter out) throws IOException {
        synchronized (products) {
            out.write(String.valueOf(products.size()));
            out.newLine();
            for (Product p : products) {
                out.write(p.getBasicInfo());
                out.newLine();
            }
            out.flush();
        }
    }

    private void handleStatusByDate(BufferedWriter out, LocalDate date) throws IOException {
        int expiredCount = 0;
        int outWarrantyCount = 0;
        StringBuilder expiredInfo = new StringBuilder();
        StringBuilder warrantyInfo = new StringBuilder();

        synchronized (products) {
            for (Product p : products) {
                if (p instanceof FoodProduct food) {
                    if (food.isExpired(date)) {
                        expiredCount++;
                        expiredInfo.append(food.getId()).append(";").append(food.getName())
                                .append(";").append(food.getExpirationDate()).append("\n");
                    }
                } else if (p instanceof NonFoodProduct nf) {
                    if (!nf.isInWarranty(date)) {
                        outWarrantyCount++;
                        warrantyInfo.append(nf.getId()).append(";").append(nf.getName())
                                .append(";").append(nf.getWarrantyEndDate()).append("\n");
                    }
                }
            }
        }

        out.write("EXPIRED_FOOD:" + expiredCount);
        out.newLine();
        out.write(expiredInfo.toString());

        out.write("OUT_OF_WARRANTY:" + outWarrantyCount);
        out.newLine();2
        out.write(warrantyInfo.toString());

        out.flush();
    }
}