def is_palindrome(number):
    str_num = str(number)
    if str_num == str_num[::-1]:
        return True 
    else:
        return False  

num = int(input(f"Enter number: "))
result = is_palindrome(num)
print(f"{num} is polidrome: {result}")
