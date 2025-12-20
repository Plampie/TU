import java.util.ArrayList;
import java.util.List;

public class ServiceCenter {

    private final List<RepairOrder> orders = new ArrayList<>();
    private int nextId = 1;

    public synchronized int registerOrder(String carRegNumber, String description) {
        for (RepairOrder order : orders) {
            if (order.getCarRegNumber().equalsIgnoreCase(carRegNumber) &&
               (order.getStatus().equals("NEW") || order.getStatus().equals("IN_PROGRESS"))) {
                return -1; 
            }
        }

        int id = nextId++;
        orders.add(new RepairOrder(id, carRegNumber, description, "NEW"));
        return id;
    }

    public synchronized boolean changeStatus(int id, String newStatus) {
        for (RepairOrder order : orders) {
            if (order.getId() == id) {
                order.setStatus(newStatus);
                return true;
            }
        }
        return false;
    }

    public synchronized List<RepairOrder> getOrdersByStatus(String status) {
        List<RepairOrder> result = new ArrayList<>();
        for (RepairOrder order : orders) {
            if (order.getStatus().equalsIgnoreCase(status)) {
                result.add(order);
            }
        }
        return result;
    }

    public synchronized List<RepairOrder> getAllOrders() {
        return new ArrayList<>(orders);
    }
}