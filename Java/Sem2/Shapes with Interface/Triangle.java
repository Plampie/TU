public class Triangle implements Drawable {
    private Double base;
    private Double height;

    public Triangle(Double base, Double height) {
        this.base = base;
        this.height = height;
    }

    public double getBase() {
        return base;
    }

    public double getHeight() {
        return height;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a triangle.");
    }
}
