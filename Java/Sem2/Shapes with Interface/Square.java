public class Square implements Drawable {
    private Double side;

    public Square(Double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a square.");
    }
}
