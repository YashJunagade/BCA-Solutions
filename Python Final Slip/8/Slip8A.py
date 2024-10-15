from collections import Counter

def findRepeated(t):
    counts = Counter(t)

    repeate = []
    for item, count in counts.items():
        if count > 1 :
            repeate.append(item)

    return repeate

t = (1, 2, 3, 4, 5, 1, 2, 3)
repeatedT = findRepeated(t)
print(repeatedT)