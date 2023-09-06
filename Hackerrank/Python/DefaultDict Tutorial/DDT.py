# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import defaultdict

n, m = map(int, input().split())

d = defaultdict(list)

for i in range(n):
    d['A'].append(input())
    
for i in range(m):
    d['B'].append(input())

output = ""
position = 1
for i in d['B']:
    for j in d['A']:
        if i == j: #each element in d['B'] is compared to every element in d['A']
            output += str(position)
            output += " "
        position += 1
    
    #We print output after comparing an element in d['B'] to every element in d['A']
    if output == "": #AKA no matches found
        output = "-1"
    print(output)
    
    #Reset position and output string
    position = 1 
    output = ""