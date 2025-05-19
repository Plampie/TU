class ATM:
    def __init__ (self, iban, balance, pin):
        self.iban = iban
        self.balance = balance
        self.pin = pin

    def auth (self, input_pin):
        return input_pin == self.pin

    def deposit (self):
        print(f"The current amount is {self.balance} lv.")
        try:
            amount = float(input("Enter amount you want to deposit: "))
            if amount > 0:
                self.balance += amount
                print (f"Successfull! /n The deposit amount is {amount}lv. /n The new balancce is {self.balance: .2f}lv.")
            else: 
                print("Sum needs to be in scope of balance!")
        except ValueError:
            print("Enter valid sum!")

    def withdraw (self):
        print(f"The current balance is {self.balance} lv.")
        try:
            sum = float(input("Enter sum you want to withdraw: "))
            pin_auth = print("Enter you pin code: ")
            if not self.auth(pin_auth):
                print("Wrong PIN!")
                return
            if sum > 0 and sum <= self.balance:
                self.balance -= sum
                print(f"Successful withdraw of {sum} lv. Remaining: {self.balance} lv.")
            elif sum > self.balance:
                print("Not enough money in balance.")
            else:
                print("Sum needs to be in scope of balance!")
        except ValueError:
            print("Invalid sum!")
    
    def info (self):
        print("\n Info:")
        print(f"IBAN: {self.iban}")
        print(f"Balance: {self.balance} lv.")
 
    def menu(self):
        print("Welcome!")
        while True:
            print("\n1. Deposit")
            print("2. Withdraw")
            print("3. Information")
            print("4. Exit")
            choice = input("Enter your choice: ")

            if choice == "1":
                self.deposit()
            elif choice == "2":
                self.withdraw()
            elif choice == "3":
                self.info()
            elif choice == "4":
                print("Thank you! Goodbye!")
                break
            else:
                print("Invalid option. Try again")

def main():
    iban = input("Enter IBAN: ")
    pin = input("Enter PIN: ")
    try:
        balance = int(input("Enter balance: "))
    except ValueError:
        print("Enter a valid amount!")
        return

    atm = ATM(iban, pin, balance)
    atm.menu()

main()