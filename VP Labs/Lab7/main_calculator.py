import operations

print("Simple Calculator")
print("1. Add\n2. Sub\n3. Miltiplication\n4. Division")
choice = int(input("Enter your choice (1-4): "))

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

if choice == 1:
    print(f"The result of addition is: {operations.add(num1, num2)}")
elif choice == 2:
    print(f"The result of subtraction is: {operations.subtract(num1, num2)}")
elif choice == 3:
    print(f"The result of multiplication is: {operations.multiply(num1, num2)}")
elif choice == 4:
    print(f"The result of division is: {operations.divide(num1, num2)}")
else:
    print("Ïnvalid choice!")
