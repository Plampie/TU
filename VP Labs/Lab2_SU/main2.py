number = int(input("Enter number of words: "))
wordlist = [str(input("Enter words: ")) for i in range (number)]
longwords = [word for word in wordlist if len(word) > 5]

print(f"Words with charactes > 5 are: {longwords}")
