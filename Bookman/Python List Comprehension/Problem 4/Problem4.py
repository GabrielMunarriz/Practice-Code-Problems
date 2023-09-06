# Create a list of all the consonants in the string “Yellow Yaks like yelling and yawning and yesturday they yodled while eating yuky yams”

string = "Yellow Yaks like yelling and yawning and yesturday they yodled while eating yuky yams"

#My Method
list = [x for x in string if x not in ['a', 'e', 'i', 'o', 'u', ' ']]
print(list)