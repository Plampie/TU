import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArithmeticCalculator calc = new ArithmeticCalculator();

        System.out.println("Enter first number:");
        double a = scanner.nextDouble();

        System.out.println("Enter second number:");
        double b = scanner.nextDouble();

        try {
            double result = calc.divide(a, b);
            System.out.println("Result: " + result);
        } catch (DivisionByZeroException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
