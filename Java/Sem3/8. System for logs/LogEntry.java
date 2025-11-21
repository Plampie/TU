import java.time.LocalDateTime;

public class LogEntry {
    private String message;
    private LocalDateTime dateTime;

    public LogEntry(String message, LocalDateTime dateTime) {
        this.message = message;
        this.dateTime = dateTime;
    }

    @Override
    public String toString() {
        return dateTime.toString() + " - " + message;
    }
}
