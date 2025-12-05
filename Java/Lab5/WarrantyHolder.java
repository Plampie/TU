import java.time.LocalDate;

public interface WarrantyHolder {
    LocalDate getWarrantyEndDate();
    boolean isInWarranty(LocalDate onDate);
}
