numberOfEntries = int(input())
entriesList = []

for i in range(numberOfEntries):
    x = input()
    entriesList.append(x)

#print(entriesList)

for i in range(len(entriesList)):
    if i % 2 == 0:
        print(entriesList[i])