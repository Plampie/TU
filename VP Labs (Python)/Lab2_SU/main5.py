n = int(input("Enter a numer for list len: "))
div = int(input("Enter a numer for comparing: "))
list = [int(input("Number: ")) for i in range(0, n)]
avglist = sum(list) / len(list)
new_list = [num for num in list if num < avglist and num > div]

print(f"Avg = {avglist}")
print(f"New list is {new_list}")