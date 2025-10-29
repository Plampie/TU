abstract class Car implements Extras {
    private String make;
    private String model;
    private int year;
    private double engineCapacity; // in cc
    private double price;

    private Extras.ACType acType;
    private Extras.Interior interior;
    private Extras.RimType rimType;

    public Car(String make, String model, int year, double engineCapacity, double price, Extras.ACType acType, Extras.Interior interior, Extras.RimType rimType) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.engineCapacity = engineCapacity;
        this.price = price;
        this.acType = acType;
        this.interior = interior;
        this.rimType = rimType;
    }

    // getters
    public String getMake() { return make; }
    public String getModel() { return model; }
    public int getYear() { return year; }
    public double getEngineCapacity() { return engineCapacity; }
    public double getPrice() { return price; }

    public Extras.ACType getACType() { return acType; }
    public Extras.Interior getInterior() { return interior; }
    public Extras.RimType getRimType() { return rimType; }

    @Override
    public double extrasPrice() {
        double total = 0;

        if (acType == Extras.ACType.MANUAL) total += 500;
        else if (acType == Extras.ACType.AUTOMATIC) total += 900;

        if (interior == Extras.Interior.LEATHER) total += 1200; // FABRIC = 0
        if (rimType == Extras.RimType.ALLOY) total += 600;      // STEEL  = 0

        return total;
    }

    public abstract double ecoTax();

}
