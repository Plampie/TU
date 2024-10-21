#ZAD 1
n = int(input("Enter the number of the array: "))
if n <= 0: 
    print("Please enter a number higher than 1: ")
else:
    numbers = []
    
for i in range(n):
    num = int(input("Enter numbers: "))
    numbers.append(num)
    
higher_num = max(numbers)

print(f"The highest numver is {higher_num}")

## VERSION 2
max = 0
n = int(input("Enter the number of the array: "))

if i in range(n):
    number = int(input())
    if number >= max:
        max = number

print(f"Max number = {max}")



#ZAD 2
n = int(input("Enter the number of the array: "))

total_sum = sum(int(input("Enter numbers")) for i in range(n))
    
print(f"Total sum is {total_sum}")

##VERSION 2
sum = 0
n = int(input("Enter the number of the array: "))

if i in range(n):
    number = int(input())
    sum += num

print(f"Sum of number = {sum}")


#ZAD 3
n = int(input("Enter the number of the array: "))

for i in range(1, n+1):
    print('*' * i)


#ZAD 4
def prime(number):
    if number <= 1:
        return False
    if number % 1 and number % number:
        if number % 2 == 0:
            return False
        if number % 3 == 0:
            return False	
        if number % 5 == 0:
            return False
        if number % 7 == 0:
            return False
        else:
            return True

n = int(input("Enter the number of the array: "))

if prime(n):
    print(f"{n} is a prime number")
else: 
    print(f"{n} is not prime number")
