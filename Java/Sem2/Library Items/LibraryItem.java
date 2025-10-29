abstract class LibraryItem {
    private String title;

    public LibraryItem(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public abstract void displayInfo();
}
