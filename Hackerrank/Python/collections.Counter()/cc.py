# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter

x = int(input()) #number of shoes
availableShoes = list(map(int, input().split())) #identified by SIZE
n = int(input()) #number of customers

shoeFrequencyDict = Counter(availableShoes)
revenue = 0

for i in range (n):
    desiredShoe, customerOffer = map(int, input().split())
    for j in shoeFrequencyDict: #we iterate through the keys
        if j == desiredShoe and shoeFrequencyDict[j] > 0:
            revenue += customerOffer
            shoeFrequencyDict[j] -= 1

print(revenue)