import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Dealership dealership = new Dealership();

        System.out.println("=== Add 5 Diesel cars ===");
        for (int i = 0; i < 5; i++) {
            dealership.addCar(readDiesel(sc, i + 1));
        }

        System.out.println("\n=== Add 5 Petrol cars ===");
        for (int i = 0; i < 5; i++) {
            dealership.addCar(readPetrol(sc, i + 1));
        }

        System.out.println("\n=== Add 5 Electric cars ===");
        for (int i = 0; i < 5; i++) {
            dealership.addCar(readElectric(sc, i + 1));
        }

        System.out.println("\n=== All cars ===");
        dealership.showAllCars();

        System.out.println("\nTotal eco tax: " + dealership.totalEcoTax());

        // ----- Zad 4: filter by extra -----
        System.out.println("\n=== Filter by extra ===");
        System.out.print("Category (AC / INTERIOR / RIMS): ");
        String category = sc.nextLine();
        System.out.print("Value (MANUAL/AUTOMATIC or FABRIC/LEATHER or STEEL/ALLOY): ");
        String value = sc.nextLine();

        dealership.filterByExtra(category, value);
        sc.close();
    }

    private static DieselCar readDiesel(Scanner sc, int n) {
        System.out.println("Diesel #" + n);
        System.out.print("Make: "); String make = sc.nextLine();
        System.out.print("Model: "); String model = sc.nextLine();
        System.out.print("Year: "); int year = Integer.parseInt(sc.nextLine());
        System.out.print("Engine capacity (cc): "); double eng = Double.parseDouble(sc.nextLine());
        System.out.print("Price: "); double price = Double.parseDouble(sc.nextLine());

        Extras.ACType ac = askAC(sc);
        Extras.Interior interior = askInterior(sc);
        Extras.RimType rim = askRim(sc);

        return new DieselCar(make, model, year, eng, price, ac, interior, rim);
    }

    private static PetrolCar readPetrol(Scanner sc, int n) {
        System.out.println("Petrol #" + n);
        System.out.print("Make: "); String make = sc.nextLine();
        System.out.print("Model: "); String model = sc.nextLine();
        System.out.print("Year: "); int year = Integer.parseInt(sc.nextLine());
        System.out.print("Engine capacity (cc): "); double eng = Double.parseDouble(sc.nextLine());
        System.out.print("Price: "); double price = Double.parseDouble(sc.nextLine());

        Extras.ACType ac = askAC(sc);
        Extras.Interior interior = askInterior(sc);
        Extras.RimType rim = askRim(sc);

        return new PetrolCar(make, model, year, eng, price, ac, interior, rim);
    }

    private static ElectricCar readElectric(Scanner sc, int n) {
        System.out.println("Electric #" + n);
        System.out.print("Make: "); String make = sc.nextLine();
        System.out.print("Model: "); String model = sc.nextLine();
        System.out.print("Year: "); int year = Integer.parseInt(sc.nextLine());
        System.out.print("Engine capacity (cc): "); double eng = Double.parseDouble(sc.nextLine());
        System.out.print("Price: "); double price = Double.parseDouble(sc.nextLine());
        System.out.print("Battery (kWh): "); double batt = Double.parseDouble(sc.nextLine());

        Extras.ACType ac = askAC(sc);
        Extras.Interior interior = askInterior(sc);
        Extras.RimType rim = askRim(sc);

        return new ElectricCar(make, model, year, eng, price, batt, ac, interior, rim);
    }


    private static Extras.ACType askAC(Scanner sc) {
        System.out.print("AC (MANUAL/AUTOMATIC): ");
        return Extras.ACType.valueOf(sc.nextLine().toUpperCase());
    }

    private static Extras.Interior askInterior(Scanner sc) {
        System.out.print("Interior (FABRIC/LEATHER): ");
        return Extras.Interior.valueOf(sc.nextLine().toUpperCase());
    }

    private static Extras.RimType askRim(Scanner sc) {
        System.out.print("Rims (STEEL/ALLOY): ");
        return Extras.RimType.valueOf(sc.nextLine().toUpperCase());
    }
}
