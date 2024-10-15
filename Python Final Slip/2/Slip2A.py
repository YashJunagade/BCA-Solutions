def countCase(str):
    uppercaseCount = 0
    lowercaseCount = 0

    for ch in str:
        if ch.isupper():
            uppercaseCount += 1
        elif ch.islower() :
            lowercaseCount += 1

    print(f"No of Uppercase Character : {uppercaseCount}")
    print(f"No of Lowercase character : {lowercaseCount}")


str = input("Enter string : ")
countCase(str)
