n = int(input("Enter number: "))
list = [int(input("Enter a number: ")) for i in range (0, n)]
listeven = [num for num in list if num % 2 == 0]
listodd = [num for num in list if num % 2 != 0]

print(f"The even numbers are {listeven}")
print(f"The odd numbers are {listodd}")