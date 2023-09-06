# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import permutations

s, r = input().split()
permutationsList = list(permutations(s, int(r)))
permutationsList.sort()


for i in permutationsList:
    output = ""
    for j in i:
        output += j
    print(output)
