import java.time.LocalDate;

public abstract class Product {
    protected int id;
    protected String name;
    protected int quantity;
    protected String category;
    protected double basePrice;

    public Product(int id, String name, int quantity, String category, double basePrice) {
        this.id = id;
        this.name = name;
        this.quantity = quantity;
        this.category = category;
        this.basePrice = basePrice;
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public int getQuantity() { return quantity; }
    public String getCategory() { return category; }
    public double getBasePrice() { return basePrice; }

    public String getBasicInfo() {
        return id + ";" + name + ";" + category + ";" + basePrice + ";" + quantity;
    }
}