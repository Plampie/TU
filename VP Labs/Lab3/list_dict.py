number = int(input("Enter number: "))
list = list(range(1, number + 1))
dict = {list[i]:list[-(i + 1)] for i in range(number)}
print(f"List: {list}")
print(f"Dict: {dict}")