import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<LibraryItem> library = new ArrayList<>();

        library.add(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
        library.add(new Book("1984", "George Orwell"));
        library.add(new Magazine("National Geographic", 202));
        library.add(new Magazine("Science Weekly", 45));

        for (LibraryItem item : library) {
            item.displayInfo();
        }
    }
}
