list1 = [int(input("Enter a number list 1: "))for i in range (1, 10)]
list2 = [int(input("Enter a number list 2: "))for p in range (1, 10)]
intersec = set(list1).intersection(list2)

print(f"List 1: {list1}")
print(f"List 2: {list2}")
print(f"Intersection of lists is {intersec}")
