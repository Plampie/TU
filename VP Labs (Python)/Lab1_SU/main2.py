points = int(input("Enter your points"))
if points > 100:
    print("Invalid value! Please enter a number between 0 and 100!")
if points in range(0, 30):
    print("Your score is a F (2)")
if points in range(31, 50):
    print("Your score is a D (3)")
if points in range(51, 70):
    print("Your score is a C (4)")
if points in range(71, 85):
    print("Your score is a B (5)")
if points in range (86, 100):
    print("Your score is a A (6)")