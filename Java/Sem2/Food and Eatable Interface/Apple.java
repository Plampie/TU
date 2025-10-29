public class Apple extends Food implements Eatable {

    public Apple() {
        super("Apple");
    }

    @Override
    public void describe() {
        System.out.println("A sweet red fruit.");
    }

    @Override
    public void eat() {
        System.out.println("You eat the apple.");
    }
}
