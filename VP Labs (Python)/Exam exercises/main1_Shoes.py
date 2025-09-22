class Shoes:
    def __init__(self, brand, price, color, size, quantity):
        self.brand = brand
        self.price = price
        self.color = color
        self.size = size
        self.quantity = quantity

    def Sale(self, quantity):
        if quantity <= self.quantity:
            self.quantity -= quantity
            print(f"Sold {quantity} pairs of {self.brand} shoes. Remaining stock: {self.quantity}")
        else:
            print(f"Insufficient stock to sell {quantity} pairs.")

    def Purchase(self, quantity):
        self.quantity += quantity
        print(f"Added {quantity} pairs of {self.brand} shoes. New stock: {self.quantity}")


# Create a list of 7 shoes instances
shoes_list = [
    Shoes("Nike", 120, "Black", 42, 10),
    Shoes("Adidas", 100, "White", 40, 15),
    Shoes("Puma", 90, "Red", 41, 20),
    Shoes("Reebok", 85, "Blue", 43, 12),
    Shoes("Fila", 70, "Black", 39, 18),
    Shoes("Converse", 65, "Green", 44, 8),
    Shoes("New Balance", 110, "White", 40, 5)
]


# Function to sort shoes by price in descending order
def sort_price(shoes_list):
    sorted_list = sorted(shoes_list, key=lambda x: x.price, reverse=True)
    for shoe in sorted_list:
        print(f"Brand: {shoe.brand}, Price: {shoe.price}, Color: {shoe.color}, Size: {shoe.size}, Quantity: {shoe.quantity}")


# Function to search for shoes by brand and size
def shoes_searching(shoes_list, brand, size):
    average_price = sum(shoe.price for shoe in shoes_list) / len(shoes_list)
    result = [shoe for shoe in shoes_list if shoe.brand == brand and shoe.size == size and shoe.price < average_price]
    return result


# Function to find the cheapest shoes of a specific color
def cheapest_shoes(shoes_list, color):
    color_shoes = [shoe for shoe in shoes_list if shoe.color.lower() == color.lower()]
    if color_shoes:
        cheapest_shoe = min(color_shoes, key=lambda x: x.price)
        print(f"Cheapest shoes: Brand: {cheapest_shoe.brand}, Price: {cheapest_shoe.price}, Size: {cheapest_shoe.size}, Quantity: {cheapest_shoe.quantity}")
    else:
        available_colors = {shoe.color for shoe in shoes_list}
        print(f"{color} is not available. Available colors are: {', '.join(available_colors)}")


# Function to delete all shoes of a specific brand
def delete_shoes(shoes_list, brand):
    shoes_list[:] = [shoe for shoe in shoes_list if shoe.brand != brand]
    print(f"All shoes of brand {brand} have been removed.")


# Example Usage
# Sort shoes by price
print("Shoes sorted by price:")
sort_price(shoes_list)

# Search for shoes
print("\nSearching for Adidas shoes size 40 with price below average:")
search_results = shoes_searching(shoes_list, "Adidas", 40)
for shoe in search_results:
    print(f"Brand: {shoe.brand}, Price: {shoe.price}, Color: {shoe.color}, Size: {shoe.size}, Quantity: {shoe.quantity}")

# Find the cheapest shoes of a specific color
print("\nCheapest shoes of color 'Black':")
cheapest_shoes(shoes_list, "Black")

# Delete all shoes of a specific brand
print("\nDeleting all Nike shoes:")
delete_shoes(shoes_list, "Nike")

# Display updated list
print("\nUpdated list of shoes:")
for shoe in shoes_list:
    print(f"Brand: {shoe.brand}, Price: {shoe.price}, Color: {shoe.color}, Size: {shoe.size}, Quantity: {shoe.quantity}")