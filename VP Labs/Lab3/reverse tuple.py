number = input("Enter a number: ")
tuple_forward = tuple(int(n) for n in number)
tuple_reverse = tuple(int(n) for n in number[::-1])
print(f"Forward tuple is {tuple_forward}")
print(f"Reverse tuple is {tuple_reverse}")