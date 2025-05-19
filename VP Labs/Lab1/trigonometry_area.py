#ЗАДАЧА 1
a = float(input("a = : "))
b = float(input("b = : "))
h = float(input("h = : "))

area = (a + b) * h / 2
area_rounded = round(area, 2)

print(f"S = : {area_rounded}")



#ЗАДАЧА 2
pi = 3.141592653589793
r = float(input("Въведете r: "))

area = pi * r ** 2
perimeter = 2 * pi * r

area_rounded = round(area, 3)
perimeter_rounded = round(perimeter, 3)

print(f"S = : {area_rounded}")
print(f"P = : {perimeter_rounded}")



#ЗАДАЧА 3
hours = float(input("Enter Hours: "))
rate = float(input("Enter Rate: "))

pay = hours * rate

print(f"Pay: {pay}")

