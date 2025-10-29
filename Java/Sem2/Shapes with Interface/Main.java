import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<Drawable> shapes = new ArrayList<>();

        shapes.add(new Triangle(5, 8));
        shapes.add(new Square(4));
        shapes.add(new Triangle(3, 6));
        shapes.add(new Square(10));

        for (Drawable shape : shapes) {
            shape.draw();
        }
    }
}
