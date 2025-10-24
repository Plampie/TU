public class Main {
   public static void main(String[] args) {

       double r = 3.38;
       System.out.printf("r = %.2f\n", r);
       System.out.printf("Area = %.2f\n", Circle.area(r));
       System.out.printf("Circumference = %.2f\n", Circle.circumference(r));

       Car c1 = new Car("Toyota");
       System.out.printf("Count = %.2f\n", Car.getCount());

       BankAccount acc = new BankAccount("Plamena", 267.78);
       double interest = acc.calculateinterest(acc.getBalance());
       System.out.printf("Interest = %s\n", acc.getOwner());
       System.out.printf("Balance = %.2f\n", acc.getBalance());
       System.out.printf("Interest = %.2f\n", interest);

       double usd = 120;
       double eur = CurrencyConverter.convertUsdToEur(usd);
       double bgn = CurrencyConverter.convertUsdToEur(eur);
       System.out.println(usd + "USD = " + eur + "EUR");
       System.out.println(eur + "EUR = " + bgn + "BGN");
   }

    
}