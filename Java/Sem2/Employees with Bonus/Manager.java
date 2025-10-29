public class Manager extends Worker {
    public Manager(String name, double baseSalary) {
        super(name, baseSalary);
    }

    @Override
    public double calculateTotalPay() {
        return getBaseSalary() * 1.2;
    }
}
