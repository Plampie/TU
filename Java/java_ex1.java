public class Circle {
    
    public static final double pi = 3.14159;

    public static double area(double r) {
        return pi * r * r;
    }

    public static double circumference(double r) {
        return 2 * pi * r;
    }

}

public class Main {
    public static void main(String[] args) {
        
        double r = 3;
        
        System.out.println("r = " + r);
        System.out.println("Area = " + area(r));
        System.out.println("Circumference =" + circumference(r));
    }
}