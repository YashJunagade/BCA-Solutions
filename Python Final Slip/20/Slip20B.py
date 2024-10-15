def generateDict(n):
  return {x : x*x for x in range(1, n+1)}

n = 5
myDict = generateDict(n)
print(myDict)