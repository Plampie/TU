file_name = "C:\\Users\\plami\\OneDrive\\Desktop\\plammy.txt"
try:
    with open(file_name, "r") as file:
        for line in file:
            print(line.strip())
except FileExistsError:
    print("File not found.")