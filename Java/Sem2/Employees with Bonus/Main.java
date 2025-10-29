import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<Worker> employees = new ArrayList<>();

        employees.add(new Manager("Plammy", 10000));
        employees.add(new Intern("Petq", 2000));
        employees.add(new Manager("Miha", 6000));
        employees.add(new Intern("Sami", 1800));

        for (Worker worker : employees) {
            System.out.printf("%s earns %.2f%n", worker.getName(), worker.calculateTotalPay());
        }
    }
}
