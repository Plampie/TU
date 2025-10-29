public class Magazine extends LibraryItem {
    private int issueNumber;

    public Magazine(String title, int issueNumber) {
        super(title);
        this.issueNumber = issueNumber;
    }

    public int getIssueNumber() {
        return issueNumber;
    }

    @Override
    public void displayInfo() {
        System.out.println("Magazine: " + getTitle() + " (Issue " + issueNumber + ")");
    }
}
