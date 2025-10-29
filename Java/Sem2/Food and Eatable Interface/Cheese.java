public class Cheese extends Food implements Eatable {

    public Cheese() {
        super("Cheese");
    }

    @Override
    public void describe() {
        System.out.println("Made from milk.");
    }

    @Override
    public void eat() {
        System.out.println("You eat the cheese.");
    }
}
