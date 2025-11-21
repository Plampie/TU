import java.util.LinkedList;

public class ActionHistory implements HistoryInterface {
    private LinkedList<String> history = new LinkedList<>();

    @Override
    public void addAction(String action) {
        if (history.size() == 5) {
            history.removeFirst();
        }
        history.addLast(action);
        showHistory();
    }

    @Override
    public void showHistory() {
        if (history.isEmpty()) {
            System.out.println("History is empty.");
            return;
        }

        System.out.println("Current history:");
        for (String act : history) {
            System.out.println(act);
        }
    }
}
