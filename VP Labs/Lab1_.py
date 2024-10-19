"""""# ZAD 1
a = float(input("a = :"))
b = float(input("b = :"))
h = float(input("h = :"))

area = (a + b) * h / 2
area_rounded = round(area, 2)

print(f'Area = {area_rounded}')


#ZAD 2
r = float(input("Radius is: "))
pi = 3.14159265359

area = pi * r ** 2
perimeter = 2* pi * r 

S = round(area, 3)
P = round(perimeter, 3)

print(f'S = {S}')
print(f'P = {P}')


#ZAD 3
hours = int(input("Enter hours: "))
rate = float(input ("Enter rate: "))

pay = hours*rate

print(f'Pay is: {pay}')"""""


#ZAD 4
price = float(input ("Price of product is "))
discount = int(input ("Discount of product is "))

final_price = price - discount/100*price
final_price_rounded = round(final_price, 2)

print(f'Final price is {final_price_rounded}')

