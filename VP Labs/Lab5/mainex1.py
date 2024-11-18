# Напишете програма, в която се създава списък (Ist_10) с 10 на брой елементи. 
# Всеки елемент задължително трябва да бъде цяло положително число, 
# въведено от потребителя (12т.)
Ist_10 = []
for i in range(10):
    while True:
        try:
            number = int(input(f"Enter positive number {i + 1}: "))
            if number > 0:
                Ist_10.append(number)
                break
            else:
                print("Please enter a positive number.")
        except ValueError:
            print("Please enter a valid integer.")

# Изведете броят на нечетните числа в списъка (Ist_10) (7т.)
odd_count = len([num for num in Ist_10 if num % 2 != 0])
print("The number of odd numbers in the list Ist_10 is: ", odd_count)

# Намерете средноаритметичната стойност на числата в списъка (Ist_10) (7т.)
average = sum(Ist_10) / len(Ist_10)
print("The average value of the numbers in the list Ist_10 is:", average)

# Създайте втори списък (Ist_5), който да съхранява петте най-големи числа 
# от първия списък (Ist_10), които са кратни на 2 (10т.)
Ist_5 = sorted([num for num in Ist_10 if num % 2 == 0], reverse=True)[:5]
print("List Ist_5 with the five largest even numbers from Ist_10:", Ist_5)

# Сортирайте втория списък (Ist_5) в низходящ ред (7т.)
Ist_5.sort(reverse=True)
print("List Ist_5 after sorting in descending order:", Ist_5)

# Да се изтрият всички елементи от втория списък (Ist_5), които са с четен индекс (7т.)
Ist_5 = [num for i, num in enumerate(Ist_5) if i % 2 != 0]
print("List Ist_5 after removing elements with even indices:", Ist_5)