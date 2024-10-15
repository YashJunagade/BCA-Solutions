def removeOddIndex(str):
    return ''.join(char for index, char in enumerate(str) if index % 2 == 0)

str = input("Enter String : ")
result = removeOddIndex(str)
print(f"String after remove character from odd index : {result}")
