def insert_sum_between_numbers(list):
    final_list = []
    for i in range(len(list) - 1):
        final_list.append(list[i])
        sum = [list[i] + list[i + 1]]
        final_list.append(sum)
    final_list.append(list[-1])
    return final_list

num = int(input(f"Enter number of random numbers: "))
orglist = [int(input(f"Enter {i + 1}: ")) for i in range(num)]
result_list = insert_sum_between_numbers(orglist)
print(f"New list is {result_list}")


#NUMBER 2
import random
list = []
n = 10
for i in range(n):
    list.append(random.randint(1,9))
sum = 0
len = len(list)
temp = 1
while temp <= len:
    sum = list[temp - 1] + list[temp]
    temp += 2
print(list)
