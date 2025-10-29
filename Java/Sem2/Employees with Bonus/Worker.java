abstract class Worker {
    private String name;
    private Double baseSalary;

    public Worker(String name, Double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }

    public String getName() {
        return name;
    }
    public Double getbaseSalary() {
        return baseSalary;
    }

    public abstract double calculateTotalPay();
}
