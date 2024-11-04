def sum(num1, num2):
    return num1 + num2

def sub(num1, num2):
    return num1 - num2

def milti(num1, num2):
    return num1 * num2

def div(num1, num2):
    if num2 == 0:
        return "Error! Dividing with 0!"
    return num1 // num2  

def calculator():
    print("Choose operation: sum, sub, milti, div")
    operation = input("Operation: ")

    if operation not in ['sum', 'sub', 'milti', 'div']:
        print("Invalid operation")
        return

    try:
        number1 = int(input("Enter first num: "))
        number2 = int(input("Enter second num: "))
    except ValueError:
        print("Enter valid numbers!")
        return

    if operation == 'sum':
        result = sum(number1, number2)
    elif operation == 'sub':
        result = sub(number1, number2)
    elif operation == 'milti':
        result = milti(number1, number2)
    elif operation == 'div':
        result = div(number1, number2)

    print(f"Result = {result}")

calculator()
