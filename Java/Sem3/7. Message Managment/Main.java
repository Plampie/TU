import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MessageManager manager = new MessageManager();

        System.out.println("Enter messages. Type 'undo' to remove last, 'exit' to quit, 'print' to show all.");

        while (true) {
            String input = scanner.nextLine();

            if (input.equals("exit")) {
                System.out.println("Exiting...");
                break;
            } else if (input.equals("undo")) {
                manager.undo();
            } else if (input.equals("print")) {
                manager.printMessages();
            } else {
                try {
                    manager.addMessage(input);
                } catch (EmptyMessageException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }
}
