# Да се състави програма за управление на онлайн бутик. 
# За целта създайте клас ClothesShop с полета: id (номер на артикула), 
# type (вид на артикула), brand (марка на артикула), price (цена на артикула), 
# quantity (количество/ брой). 
# Да се създаде конструктор, който инициализира свойствата на класа. (10т.)

class ClothesShop:
    def __init__(self, id, type, brand, price, quantity):
        self.id = id
        self.type = type
        self.brand = brand
        self.price = price
        self.quantity = quantity
        
        if not isinstance(id, int):
            raise ValueError("ID трябва да бъде цяло число.")
        if not isinstance(price, (int, float)) or price < 0:
            raise ValueError("Цената трябва да бъде положително число.")
        if not isinstance(quantity, int) or quantity < 0:
            raise ValueError("Количество трябва да бъде положително цяло число.")
    
# В класа са дефинирани и методи:
# clothe_info(self), който принтира цялата информация за съответния артикул. (5т.)
# change_price(self), който дава възможност потребителя да въведе нова цена на съответния артикул. (5т.)
# change_qty(self), който дава възможност потребителя да въведе ново количество на съответния артикул. (5т.)

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
  

# search_by_id (clothes_list, id) 
# потребителят въвежда от клавиатурата номер на артикула и 
# функцията принтира цялата информация за съответния артикул. (5т.)
def search_by_id(clothes_list, id):
    for item in clothes_list:
        if item.id == id:
            item.clothes_info()
            return
    print("Item with this ID was not found.")

# search_by_brand(clothes_list, brand)- 
# потребителят въвежда от клавиатурата марка на артикул и 
# функцията принтира списък с всички артикули на тази марка. (5т.)
def search_by_brand(clothes_list, brand):
    found = False
    for item in clothes_list:
        if item.brand.lower() == brand.lower():
            item.clothes_info()
            found = True
    if not found:
        print("No items found for this brand.")
        
# sell_clothes_by_id(clothes_list, id, num)
# потребителят въвежда от клавиатурата номер (id) и 
# желан брой/ количество (num) от даден артикул. 
# Функцията проверява има ли наличен артикул с такъв номер. 
# Ако има- проверява колко бройки има налични (quantity). 
# Ако количеството (quantity) от търсения продукт е равно или 
# по-голямо от количеството (num), което е въвел потребителя, 
# то тогава да се принтира в конзолата съобщение „Успешна продажба" и 
# от общото количество (quantity) на съответния артикул да се извади стойността (num), 
# която е въвел потребителя. В случай, че няма продукт с такъв номер да се принтира 
# в конзолата съобщение „Не е открит такъв продукт", а ако количеството(quantity) 
# от търсения продукт е по-малко от количеството (num), което е въвел потребителя 
# да се принтира в конзолата съобщение „Недостатъчна наличност". (10т.)

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

        
# Да се създадат 3 артикула (обекти-инстанции на класа ClothesShop) 
# нов списък clothes_list, където да бъдат добавени и да се съхраняват
# всички артикули (обекти). (5т.)
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