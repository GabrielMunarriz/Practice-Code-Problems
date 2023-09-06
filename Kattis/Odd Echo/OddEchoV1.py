#This variant only works if input is inputted via 1 line

userInput = input()
splitUserInput = userInput.split()
# print(splitUserInput)

numberOfEntries = int(splitUserInput[0])

for x in range(1, numberOfEntries + 1):
    # print(x)
    if x % 2 > 0:
        print(splitUserInput[x])