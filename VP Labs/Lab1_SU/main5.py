num = int(input("Enter a number: "))
num_list = []
for i in range(1, num+1):
    if num % i == 0:
        num_list.append(i)
print(f"The dels if {num} is {num_list}")