def countCases(str):
    upperCase = sum(1 for ch in str if ch.isupper())
    lowerCase = sum(1 for ch in str if ch.islower())

    print("No of Upper case character : ", upperCase)
    print("No of Lower case character : ", lowerCase)

str = input("Enter String : ")
countCases(str)