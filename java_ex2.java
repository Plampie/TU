public class Exersice2 {
    public static void main(String[] args) {
        int sideA = 3;
        int sideB = 4;
        int sideC = 5;
        int perimeter = sideA + sideB + sideC;
        System.out.println("The perimeter of the triangle is: " + perimeter);
    }
}

public class Exersice5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please enter the Side A of the triangle:");
        int sideA = scanner.nextInt();
        System.out.println("Please enter the Side B of the triangle:");
        int sideB = scanner.nextInt();
        System.out.println("Please enter the Side C of the triangle:");
        int sideC = scanner.nextInt();
        int perimeter = sideA + sideB + sideC;
        System.out.println("The perimeter of the triangle is: " + perimeter);  
    }
}

public class ArithmeticOperations {
    public static void main(String[] args) {
        int a = 10;
        int b = 25;

        System.out.println("Addition: " + (a + b));
        System.out.println("Subtraction: " + (a - b));
        System.out.println("Multiplication: " + (a * b));
        System.out.println("Division: " + (a / b));
        System.out.println("Modulus: " + (a % b));
        System.out.println("Increment: " + (++a));
        System.out.println("Decrement: " + (--b));

        System.out.println("Test Increment and Sum:" + (++a + b));
    }      
}


public class ArithmeticOperations2 {
    public static void main(String[] args) {
        int a = 10;

        System.out.println("=: " + a);
        System.out.println("+=: " + (a+=5));
        System.out.println("-=: " + (a-=6));
        System.out.println("*=: " + (a*=2));
        System.out.println("/=: " + (a/=3));
        System.out.println("%=: " + (a%=5));

    }      
}


public class ComparisonOperations {
    public static void main(String[] args) {

        int a = 10;
        int b = 5;

        boolean equalTo = a==b;
        boolean notEqualTo = a!=b;
        boolean greaterThan = a>b;
        boolean lessThan = a<b;
        boolean greaterThanOrEqualTo = a>=b;
        boolean lessThanOrEqualTo = a<=b;

        System.out.println("Equal to: " + equalTo);
        System.out.println("Not equal to: " + notEqualTo);
        System.out.println("Greater than: " + greaterThan);
        System.out.println("Less than: " + lessThan);
        System.out.println("Greater than or equal to: " + greaterThanOrEqualTo);
        System.out.println("Less than or equal to: " + lessThanOrEqualTo);

    }      
}


public class LOgicalOperations {
    public static void main(String[] args) {

        int a = 10;
        int b = 5;
        int c = 2;
        int d = 1;	

        boolean andOperation = (a > b) && (c < d);
        boolean orOperation = (a > b) || (c < d);
        boolean notOperation = !(a > b);
        boolean xorOperation = (a > b) ^ (c < d);
        boolean conditionalOperation = (a > b) ? true : false;
        boolean nullCoalescingOperation = (a > b) ? a : b;
        boolean instanceOfOperation = (a instanceof Integer);
        boolean bitwiseAndOperation = (a & b) > 0;
        boolean bitwiseOrOperation = (a | b) > 0;
        boolean bitwiseXorOperation = (a ^ b) > 0;
        boolean bitwiseNotOperation = ~a > 0;
        boolean shiftLeftOperation = (a << 1) > 0;
        boolean shiftRightOperation = (a >> 1) > 0;
        boolean unsignedShiftRightOperation = (a >>> 1) > 0;
        boolean ternaryOperation = (a > b) ? a : b;
        boolean instanceOfString = (a instanceof String);
        
        System.out.println("AND Operation: " + andOperation);
        System.out.println("OR Operation: " + orOperation);
        System.out.println("NOT Operation: " + notOperation);
        System.out.println("XOR Operation: " + xorOperation);
        System.out.println("Conditional Operation: " + conditionalOperation);
        System.out.println("Null Coalescing Operation: " + nullCoalescingOperation);
        System.out.println("Instance Of Operation: " + instanceOfOperation);
        System.out.println("Bitwise AND Operation: " + bitwiseAndOperation);
        System.out.println("Bitwise OR Operation: " + bitwiseOrOperation);
        System.out.println("Bitwise XOR Operation: " + bitwiseXorOperation);
        System.out.println("Bitwise NOT Operation: " + bitwiseNotOperation);
        System.out.println("Shift Left Operation: " + shiftLeftOperation);
        System.out.println("Shift Right Operation: " + shiftRightOperation);
        System.out.println("Unsigned Shift Right Operation: " + unsignedShiftRightOperation);
        System.out.println("Ternary Operation: " + ternaryOperation);
        System.out.println("Instance Of String: " + instanceOfString);
        
    }      
}