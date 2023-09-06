# Count the number of spaces in a string

string = "this is an example string"

#My Method
list = [y for y in range(1, len([x for x in string if x == ' ']) + 1)]
print(list)
print (len(list))

#Other Method
list = [x for x in string if x == ' ']
print (len(list))