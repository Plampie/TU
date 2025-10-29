public class Bread extends Food implements Eatable {

    public Bread() {
        super("Bread");
    }

    @Override
    public void describe() {
        System.out.println("Baked from flour.");
    }

    @Override
    public void eat() {
        System.out.println("You eat the bread.");
    }
}
