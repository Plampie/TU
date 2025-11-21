public class Book {
    private int id;
    private String title;
    private String author;
    private boolean rented;
    private String rentedBy;

    public Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.rented = false;
        this.rentedBy = null;
    }

    public int getId() {
        return id;
    }

    public boolean isRented() {
        return rented;
    }

    public void rent(String user) {
        this.rented = true;
        this.rentedBy = user;
    }

    public void returnBook() {
        this.rented = false;
        this.rentedBy = null;
    }

    @Override
    public String toString() {
        String status;
        if (rented) {
            status = "(rented by " + rentedBy + ")";
        } else {
            status = "(available)";
        }
        return "[" + id + "] " + title + " - " + author + " " + status;
    }
}
