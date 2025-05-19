start = int(input("Enter start: "))
end = int(input("Enter end: "))
numbers = input("Enter the numbers: ").split()
nums = [int(num) for num in numbers]
result = []

for i in range(len(nums)):
    for k in range(i+1, len(nums)):
        for p in range(k+1, len(nums)):
            allsum = nums[i] + nums[k] + nums[p]
            if start <= allsum <= end:
                result.append((nums[i], nums[k], nums[p], allsum))

if result:
    print(f"Results: ")
    for res in result:
        print(f"{res[0]} + {res[1]} + {res[2]} = {res[3]}")
    else:
        print(f"No combinations found.")