import java.util.ArrayList;

public class MessageManager {
    private ArrayList<String> messages = new ArrayList<>();

    public void addMessage(String message) throws EmptyMessageException {
        StringBuilder sb = new StringBuilder(message);
        boolean onlySpaces = true;
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) != ' ') {
                onlySpaces = false;
                break;
            }
        }
        if (sb.length() == 0 || onlySpaces) {
            throw new EmptyMessageException("Съобщението не може да бъде празно!");
        }
        messages.add(sb.toString());
        StringBuilder info = new StringBuilder();
        info.append("Message added. Total messages: ").append(messages.size());
        System.out.println(info.toString());
    }

    public void printMessages() {
        if (messages.isEmpty()) {
            System.out.println("No messages to show.");
            return;
        }
        System.out.println("Messages:");
        for (int i = 0; i < messages.size(); i++) {
            StringBuilder line = new StringBuilder();
            line.append(i + 1).append(". ").append(messages.get(i));
            System.out.println(line.toString());
        }
    }

    public void undo() {
        if (messages.isEmpty()) {
            System.out.println("No messages to undo.");
            return;
        }
        String removed = messages.remove(messages.size() - 1);
        StringBuilder sb = new StringBuilder();
        sb.append("Last message removed: ").append(removed);
        System.out.println(sb.toString());
    }
}
