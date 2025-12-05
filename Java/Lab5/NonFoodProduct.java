import java.time.LocalDate;

public class NonFoodProduct extends Product implements WarrantyHolder {
    private LocalDate warrantyEndDate;

    public NonFoodProduct(int id, String name, int quantity, double basePrice, LocalDate warrantyEndDate) {
        super(id, name, quantity, "nonfood", basePrice);
        this.warrantyEndDate = warrantyEndDate;
    }

    @Override
    public LocalDate getWarrantyEndDate() {
        return warrantyEndDate;
    }

    @Override
    public boolean isInWarranty(LocalDate onDate) {
        return !onDate.isAfter(warrantyEndDate);
    }
}
