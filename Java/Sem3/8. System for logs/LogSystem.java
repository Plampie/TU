import java.time.LocalDateTime;
import java.util.ArrayList;

public class LogSystem {
    private ArrayList<LogEntry> logs = new ArrayList<>();

    public void addLog(String message) throws InvalidLogMessageException {
        if (message == null) {
            throw new InvalidLogMessageException("Log message cannot be null.");
        }

        boolean onlySpaces = true;
        for (int i = 0; i < message.length(); i++) {
            if (message.charAt(i) != ' ') {
                onlySpaces = false;
                break;
            }
        }

        if (message.length() == 0 || onlySpaces) {
            throw new InvalidLogMessageException("Log message cannot be empty.");
        }

        if (logs.size() == 10) {
            logs.remove(0);
        }

        LogEntry entry = new LogEntry(message, LocalDateTime.now());
        logs.add(entry);
    }

    public void printLogs() {
        if (logs.isEmpty()) {
            System.out.println("No logs to display.");
            return;
        }

        System.out.println("Current logs:");
        for (LogEntry entry : logs) {
            System.out.println(entry.toString());
        }
    }
}
