import java.time.LocalDate;

public class FoodProduct extends Product implements Expirable {
    private LocalDate expirationDate;

    public FoodProduct(int id, String name, int quantity, double basePrice, LocalDate expirationDate) {
        super(id, name, quantity, "food", basePrice);
        this.expirationDate = expirationDate;
    }

    @Override
    public LocalDate getExpirationDate() {
        return expirationDate;
    }

    @Override
    public boolean isExpired(LocalDate onDate) {
        return onDate.isAfter(expirationDate);
    }
}
