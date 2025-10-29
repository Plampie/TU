public class SpeedSensor implements Measurable {
    private double speed;

    public SpeedSensor(double speed) {
        this.speed = speed;
    }

    @Override
    public double measure() {
        return speed;
    }
}
