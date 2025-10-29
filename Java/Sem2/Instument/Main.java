public class Main {
    public static void main(String[] args) {
        Guitar guitar = new Guitar();

        Piano piano = new Piano();

        Instrument[] instruments = { guitar, piano };

        for (Instrument instrument : instruments) {
            System.out.print(instrument.getName() + ": ");
            instrument.play();
        }
    }
}
