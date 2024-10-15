originalTuple = (("333", "33"), ("1416", "55"))
newTuple = tuple(tuple(int(x) for x in subtuple) for subtuple in originalTuple)

print('Original Tuple : ', originalTuple)
print("New Tuple : ", newTuple)