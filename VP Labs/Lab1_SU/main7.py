import random
choices = ['rock', 'papper', 'scissiors']
print("The options are: Rock, Papper, Scissiors")
player = input("Choose a player: ").lower()
if player not in choices:
    print("Invalid choice!")
else:
    computer = choices[random.randint(0,2)]
    print(f"Computer choice is {computer}")

