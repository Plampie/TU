public class ArithmeticCalculator implements ArithmeticOperations {
    @Override
    public double divide(double a, double b) throws DivisionByZeroException {
        if (b == 0) {
            throw new DivisionByZeroException("Cannot divide by zero.");
        }
        return a / b;
    }
}
