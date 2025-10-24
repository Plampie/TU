import java.math.BigDecimal;

public class BankAccount {

    private String owner;

    private double balance;

    public static double INTEREST_RATE = 0.02;

    public BankAccount(String owner, double balance){
        this.owner = owner;
        this.balance = balance;
    }

    public double calculateinterest(double amount){
        return amount * INTEREST_RATE;
    }

    public String getOwner(){
        return owner;
    }

    public double getBalance(){
        return balance;
    }


}
