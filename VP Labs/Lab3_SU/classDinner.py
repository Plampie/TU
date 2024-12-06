class Dinner:
    
    def __init__ (self, name, address):
        self.name = name
        self.address = address
        self.menu = {}
    
    def add_dishes(self, dish, price):
        self.menu[dish] = price
    
    def display_menu(self):
        print(f"Menu of {self.name}:")
        for dish, price in self.menu.items():
            print(f"{dish}: {price}lv.")

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
                print(f"{dish} x {quantity}: {subtotal:.2f}lv.")
            else:
                print(f"{dish}: Not available")
        
        print(f"\nTotal Amount: {total: .2f}")
        print("---- Thank You! ----")


restaurant = Dinner("Mr.Pizza", "123 Vasil Levski")

print("Enter menu items (type 'done' to finish):")
while True:
    dish = input("Dish name: ")
    if dish.lower() == 'done':
        break
    price = float(input(f"Price: "))
    restaurant.add_dishes(dish, price)

restaurant.display_menu()

table_number = input("Enter table number: ")
order = {}
print("Enter order (type 'done' to finish):")
while True:
    dish = input("Dish name: ")
    if dish.lower() == 'done':
        break
    quantity = int(input(f"Quantity: "))
    order[dish] = quantity

restaurant.bill(table_number, order)
    