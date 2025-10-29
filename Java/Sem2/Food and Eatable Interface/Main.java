import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Food> foods = new ArrayList<>();

        foods.add(new Apple());
        foods.add(new Bread());
        foods.add(new Cheese());

        for (Food food : foods) {
            System.out.print(food.getName() + ": ");
            food.describe();

            if (food instanceof Eatable) {
                ((Eatable) food).eat();
            }
            System.out.println();
        }
    }
}
