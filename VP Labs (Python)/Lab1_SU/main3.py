startpoint = 1
endpoint = int(input ("Enter a end of sum range: "))
sum = 0
#sum = sum(range(1, endpoint+1))
while startpoint <= endpoint:
    sum += startpoint
    startpoint += 1
    
print(f"Sum of numbers is {sum}")

