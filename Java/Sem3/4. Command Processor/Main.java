import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        CommandProcessor processor = new CommandProcessor();

        while (true) {
            String input = scanner.nextLine();

            try {
                processor.process(input);
            } catch (InvalidCommandException e) {
                System.out.println("Invalid command!");
            }
        }
    }
}
