import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LogSystem logSystem = new LogSystem();

        System.out.println("Log system started.");
        System.out.println("Type a message to log, 'print' to show logs, or 'exit' to quit.");

        while (true) {
            String input = scanner.nextLine();

            if (input.equals("exit")) {
                System.out.println("Exiting...");
                break;
            } else if (input.equals("print")) {
                logSystem.printLogs();
            } else {
                try {
                    logSystem.addLog(input);
                    System.out.println("Log added.");
                } catch (InvalidLogMessageException e) {
                    System.out.println("Error: " + e.getMessage());
                }
            }
        }
    }
}
