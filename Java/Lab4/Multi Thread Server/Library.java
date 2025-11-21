import java.util.*;

public class Library {
    private final List<Book> books = new ArrayList<>();
    private int nextId = 1;

    public synchronized String addBook(String title, String author) {
        Book b = new Book(nextId, title, author);
        books.add(b);
        nextId++;
        return "Book added: " + b.toString();
    }

    public synchronized String listAllBooks() {
    if (books.isEmpty()) {
        return "No books in the library.";
    }

    StringBuilder sb = new StringBuilder();
    sb.append("Books in library:\n");

    for (Book b : books) {
        sb.append(b.toString()).append("\n");
    }

    return sb.toString();
    }

    public synchronized String rentBook(int id, String user) {
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

    public synchronized String returnBook(int id) {
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
