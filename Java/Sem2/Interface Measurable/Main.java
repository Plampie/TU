import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Measurable> sensors = new ArrayList<>();

        sensors.add(new TemperatureSensor(22.5));
        sensors.add(new SpeedSensor(88.7));
        sensors.add(new TemperatureSensor(19.3));
        sensors.add(new SpeedSensor(65.2));

        for (Measurable sensor : sensors) {
            System.out.println("Measured value: " + sensor.measure());
        }
    }
}
