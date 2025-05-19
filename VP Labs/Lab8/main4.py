binary_file_name = "document.bin"
string = "This is good"

try:
    with open (binary_file_name, "rb") as bin_file:
        first_4_bytes = bin_file.read(4)
        first_4_bytes.decode("ascii")
        print(f"First four bytes are {first_4_bytes}")
except FileNotFoundError:
    print("File not found")
