import java.util.ArrayList;

public class Library {
    private ArrayList<Book> books = new ArrayList<>();
    private int nextId = 1;

    public String addBook(String title, String author) {
        Book b = new Book(nextId, title, author);
        books.add(b);
        nextId++;
        return "Book added: " + b.toString();
    }

    public String rentBook(int id, String user) {
        Book book = findById(id);
        if (book == null) {
            return "No book with id = " + id;
        }
        if (book.isRented()) {
            return "Book is already rented: " + book.toString();
        }
        book.rent(user);
        return "Book rented successfully: " + book.toString();
    }

    public String returnBook(int id) {
        Book book = findById(id);
        if (book == null) {
            return "No book with id = " + id;
        }
        if (!book.isRented()) {
            return "Book was not rented: " + book.toString();
        }
        book.returnBook();
        return "Book returned: " + book.toString();
    }

    private Book findById(int id) {
        for (Book b : books) {
            if (b.getId() == id) {
                return b;
            }
        }
        return null;
    }
}
