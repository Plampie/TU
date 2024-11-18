import math

def main():
    try:
        number = int(input("Enter a positive number: "))
        if number < 0:
            print("Invalid Number")
        else:
            print(f"Square root: {math.sqrt(number):.2f}")
    except ValueError:
        print("Invalid Number")
    finally:
        print("Good Bye")

if __name__ == "__main__":
    main()