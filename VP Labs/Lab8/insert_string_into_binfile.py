binary_file_name = "document.bin"
string = "This is good"

bin_file = open (binary_file_name, "wb")
bin_file.write(string.encode("ascii"))
bin_file.close()

print(f"String data '{string}' was saved in {binary_file_name}")
