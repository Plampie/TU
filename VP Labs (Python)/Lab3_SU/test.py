import json

class Dinner:
    def __init__(self, name, address):
        self.name = name
        self.address = address
        self.menu = {}

    def add_dishes(self, dish, price):
        self.menu[dish] = price

    def remove_dish(self, dish):
        if dish in self.menu:
            del self.menu[dish]
            print(f"{dish} has been removed from the menu.")
        else:
            print(f"{dish} is not in the menu.")

    def display_menu(self):
        print(f"\nMenu of {self.name}:")
        if not self.menu:
            print("The menu is empty.")
        for dish, price in self.menu.items():
            print(f"{dish}: {price:.2f} lv.")

    def save_menu_to_file(self, file_name):
        with open(file_name, 'w') as file:
            json.dump(self.menu, file, indent=4)
        print(f"Menu saved to {file_name}.")

    def load_menu_from_file(self, file_name):
        try:
            with open(file_name, 'r') as file:
                self.menu = json.load(file)
            print(f"Menu loaded from {file_name}.")
        except FileNotFoundError:
            print(f"{file_name} not found. Starting with an empty menu.")

    def totalsum(self, order):
        total = 0
        for dish, quantity in order.items():
            if dish in self.menu:
                total += self.menu[dish] * quantity
        return total

    def bill(self, table_number, order):
        print("\n---- BILL ----")
        print(f"Restaurant: {self.name}")
        print(f"Address: {self.address}")
        print(f"Table Number: {table_number}\n")
        print("Items Ordered: ")
        
        total = self.totalsum(order)
        for dish, quantity in order.items():
            if dish in self.menu:
                price = self.menu[dish]
                subtotal = price * quantity
                print(f"{dish} x {quantity}: {subtotal:.2f} lv.")
            else:
                print(f"{dish}: Not available")
        
        print(f"\nTotal Amount: {total:.2f} lv.")
        print("---- Thank You! ----")

# Main program
restaurant = Dinner("Mr.Pizza", "123 Vasil Levski")

# Load menu from file if exists
menu_file = "menu.json"
restaurant.load_menu_from_file(menu_file)

# Add or remove dishes
while True:
    action = input("\nWould you like to add, remove, display, or save the menu? (add/remove/display/save/exit): ").lower()
    if action == 'add':
        dish = input("Dish name: ")
        price = float(input(f"Price: "))
        restaurant.add_dishes(dish, price)
    elif action == 'remove':
        dish = input("Dish name to remove: ")
        restaurant.remove_dish(dish)
    elif action == 'display':
        restaurant.display_menu()
    elif action == 'save':
        restaurant.save_menu_to_file(menu_file)
    elif action == 'exit':
        break
    else:
        print("Invalid option. Please choose again.")

# Taking an order
table_number = input("\nEnter table number: ")
order = {}
print("Enter order (type 'done' to finish):")
while True:
    dish = input("Dish name: ")
    if dish.lower() == 'done':
        break
    quantity = int(input(f"Quantity: "))
    order[dish] = quantity

restaurant.bill(table_number, order)

# Save menu before exiting
restaurant.save_menu_to_file(menu_file)
