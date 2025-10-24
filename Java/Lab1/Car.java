public class Car {

    private static String model;

    private static int count;

   public Car(String model) {
       this.model = model;
       count++;
   }

    public static double getCount() {
        return count;
    }
}