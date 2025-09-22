# Function to input a valid number within a range
def input_in_range(prompt, min_val, max_val):
    while True:
        try:
            value = int(input(prompt))
            if min_val < value < max_val:
                return value
            else:
                print(f"Please enter a number between {min_val} and {max_val}!")
        except ValueError:
            print("Please enter a valid integer!")

# 1. Input the length of the list
n = input_in_range("Enter the length of the list (between 15 and 35): ", 15, 35)

# 2. Input the elements of the list
numbers = []
for i in range(n):
    num = input_in_range(f"Enter element {i + 1} (between 30 and 300): ", 30, 300)
    numbers.append(num)

print("Input list:", numbers)

# 3. Count the number of elements whose tens digit is a multiple of 3
count_tens_multiple_of_3 = sum(1 for num in numbers if (num // 10) % 3 == 0)
print("Number of elements whose tens digit is a multiple of 3:", count_tens_multiple_of_3)

# 4. Find the index of the element with the smallest value that leaves a remainder of 4 when divided by 6
min_index = -1
min_value = float('inf')
for i, num in enumerate(numbers):
    if num % 6 == 4 and num < min_value:
        min_value = num
        min_index = i
print("Index of the element with the smallest value leaving a remainder of 4 when divided by 6:", min_index)

# 5. Create a second list with elements that are two-digit numbers and multiples of 2 or 3
second_list = [num for num in numbers if 10 <= num < 100 and (num % 2 == 0 or num % 3 == 0)]
print("Second list:", second_list)

# 6. Calculate the average of elements at odd indices
odd_index_numbers = [numbers[i] for i in range(1, len(numbers), 2)]
if odd_index_numbers:
    average_odd_index = sum(odd_index_numbers) / len(odd_index_numbers)
else:
    average_odd_index = 0
print("Average of elements at odd indices:", average_odd_index)

# 7. Remove the smallest even number
even_numbers = [num for num in numbers if num % 2 == 0]
if even_numbers:
    min_even = min(even_numbers)
    numbers.remove(min_even)
    print(f"Removed the smallest even number: {min_even}")
else:
    print("No even numbers to remove.")

print("Final list:", numbers)