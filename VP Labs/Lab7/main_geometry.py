import geometry

print("Choose a geometric figure:")
print("1. Triangle\n2. Square\n3. Rectangle\n4. Rhombus\n5. Trapezoid")
choice = int(input("Enter your choice (1-5): "))

if choice == 1:
    base = float(input("Enter the base of the triangle: "))
    height = float(input("Enter the height of the triangle: "))
    print(f"The area of the triangle is: {geometry.triangle_area(base, height)}")
elif choice == 2:
    side = float(input("Enter the side of the square: "))
    print(f"The area of the square is: {geometry.square_area(side)}")
elif choice == 3:
    length = float(input("Enter the length of the rectangle: "))
    width = float(input("Enter the width of the rectangle: "))
    print(f"The area of the rectangle is: {geometry.rectangle_area(length, width)}")
elif choice == 4:
    diagonal1 = float(input("Enter the first diagonal of the rhombus: "))
    diagonal2 = float(input("Enter the second diagonal of the rhombus: "))
    print(f"The area of the rhombus is: {geometry.rhombus_area(diagonal1, diagonal2)}")
elif choice == 5:
    base1 = float(input("Enter the first base of the trapezoid: "))
    base2 = float(input("Enter the second base of the trapezoid: "))
    height = float(input("Enter the height of the trapezoid: "))
    print(f"The area of the trapezoid is: {geometry.trapezoid_area(base1, base2, height)}")
else:
    print("Invalid choice.")