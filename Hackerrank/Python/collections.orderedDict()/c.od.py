# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import OrderedDict

itemsBought = int(input())
orderedDict = OrderedDict()

for i in range(itemsBought):
    
    itemEntry = input().split() #Entire list of strings in input
    
    itemEntry_name_list = itemEntry[0:len(itemEntry)-1] #We create a list for just the item name
    itemEntry_name = " ".join(itemEntry_name_list) #We join the name here
    itemEntry_price = itemEntry[len(itemEntry)-1] #Price of each item
    
    if itemEntry_name in orderedDict:
        orderedDict[itemEntry_name] += int(itemEntry_price)
    else:
        orderedDict[itemEntry_name] = int(itemEntry_price)
    
for i in orderedDict:
    print(i, orderedDict[i])

    

