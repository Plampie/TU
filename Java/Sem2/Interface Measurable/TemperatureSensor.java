public class TemperatureSensor implements Measurable {
    private double temperature;

    public TemperatureSensor(double temperature) {
        this.temperature = temperature;
    }

    @Override
    public double measure() {
        return temperature;
    }
}
