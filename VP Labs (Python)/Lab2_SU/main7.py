word_list = (str(input("Enter words: ")).split())
dict = {}
for word in word_list:
    length = len(word)
    if length not in dict:
        dict[length] = []
    dict[length].append(word)

print(f"The dictionary is {dict}")