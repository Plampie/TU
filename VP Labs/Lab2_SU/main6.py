people = {}
num_entries = int(input("People to add: "))

for i in range(num_entries):
    name = input("Enter the name: ")
    age = int(input(f"Enter the age of {name}: "))
    people[name] = age

over_25 = {name: age for name, age in people.items() if age > 25}

print(f"People over 25 years old: {over_25}")
