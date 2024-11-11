class ClothesShop:
    def __init__(self, id, type, brand, price, quantity):
        self.id = id
        self.type = type
        self.brand = brand
        self.price = price
        self.quantity = quantity
        
        if not isinstance(id, int):
            raise ValueError("ID needs to the positive number.")
        if not isinstance(price, (int, float)) or price < 0:
            raise ValueError("Price needs to be positive number.")
        if not isinstance(quantity, int) or quantity < 0:
            raise ValueError("Quantity needs to be positive number.")
    
    def clothes_info(self):
        print(f"ID: {self.id}")
        print(f"Type: {self.type}")
        print(f"Brand: {self.brand}")
        print(f"Price: {self.price}")
        print(f"Quantity: {self.quantity}")

    def change_price(self):
        try:
            new_price = float(input("Enter new price: "))
            if new_price < 0:
                print("Price needs to be positive number.")
            else:
                self.price = new_price
                print("Price successfully added.")
        except ValueError:
            print("Please enter valid value.")

    def change_qty(self):
        try:
            new_quantity = int(input("Enter updated quantity: "))
            if new_quantity < 0:
                print("Quantity needs to be positive number.")
            else:
                self.quantity = new_quantity
                print("Quantity successfully updated.")
        except ValueError:
            print("Please enter valid value.")
  

def search_by_id(clothes_list, id):
    for item in clothes_list:
        if item.id == id:
            item.clothes_info()
            return
    print("Item with this ID was not found.")


def search_by_brand(clothes_list, brand):
    found = False
    for item in clothes_list:
        if item.brand.lower() == brand.lower():
            item.clothes_info()
            found = True
    if not found:
        print("No items found for this brand.")
        

def sell_clothe_by_id(clothes_list, id, num):
    for item in clothes_list:
        if item.id == id:
            if item.quantity >= num:
                item.quantity -= num  
                print("Success")
                return
            else:
                print("Not enough")
                return
    print("No items found")


item1 = ClothesShop(1, "T-shirt", "Nike", 29.99, 10)
item2 = ClothesShop(2, "Jeans", "Levis", 59.99, 5)
item3 = ClothesShop(3, "Jacket", "Adidas", 89.99, 2)

clothes_list = [item1, item2, item3]

search_id = int(input("Enter item ID to search: "))
search_by_id(clothes_list, search_id)

search_brand = str(input("Enter brand name: "))
search_by_brand(clothes_list, search_brand)

id_search = int(input("Enter item ID to sell: "))
num = int(input("Enter number of items to sell: "))
sell_clothe_by_id(clothes_list, id_search, num)