public class CurrencyConverter {

    public static final double USD_TO_EUR = 0.93;

    public static final double EUR_TO_BGN = 1.96;

    public static double convertUsdToEur(double usd) {
        return usd * USD_TO_EUR;
    }

    public static double convertEurToBgn(double eur) {
        return eur * EUR_TO_BGN;
    }

}
