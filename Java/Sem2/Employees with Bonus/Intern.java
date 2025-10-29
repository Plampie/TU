public class Intern extends Worker {
    public Intern(String name, double baseSalary) {
        super(name, baseSalary);
    }

    @Override
    public double calculateTotalPay() {
        return getBaseSalary();
    }
}
