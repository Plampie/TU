def replace_num(list, num):
    for i in range(len(list)):
        if list[i] > num:
            list[i] = 0
    return list

list_num = input("Enter list of numbers separated by spaces: ").split()
list_num = [int(x) for x in list_num]
numval = int(input(f"Enter number:"))
modified_list = replace_num(list_num, numval)
print(f"New list is {modified_list}")