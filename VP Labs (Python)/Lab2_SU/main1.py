import random

len = int(input("Enter the number of digits: "))
randomun = [random.randint(1, 100) for i in range(len)]
max_num = max(randomun)

print(f"The list is {randomun}")
print(f"Max number is {max_num}")