def square_area(side_len):
    return side_len ** 2

def rectangle_area(sideA, sideB):
    return sideA*sideB

def triangle_area(sideA, sideB):
    return (sideA*sideB)/2


sqr_side = float(input(f"Enter side lenght of square: "))
sqr_area = square_area(sqr_side)
print(f"The area of the square is {sqr_area}")

reg_sideA = float(input(f"Enter side a lenght of rectangle: "))
reg_sideB = float(input(f"Enter side b lenght of rectangle: "))
reg_area = rectangle_area(reg_sideA, reg_sideB)
print(f"The area of the rectangle is {reg_area}")

tri_sideA = float(input(f"Enter side a lenght of triangle: "))
tri_sideB = float(input(f"Enter side b lenght of triangle: "))
tri_area = rectangle_area(tri_sideA, tri_sideB)
print(f"The area of the triangle is {tri_area}")