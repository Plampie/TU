def read_file(file_name):
    try:
        with open(file_name, 'r', encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        print(f"Error: The file '{file_name}' was not found.")
        return ""
    except IOError as e:
        print(f"Error reading the file '{file_name}': {e}")
        return ""