import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ActionHistory history = new ActionHistory();

        while (true) {
            System.out.println("Enter an action (or type exit):");
            String action = scanner.nextLine();

            if (action.equals("exit")) {
                System.out.println("Exiting...");
                break;
            }

            history.addAction(action);
        }
    }
}
