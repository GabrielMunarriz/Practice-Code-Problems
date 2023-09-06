if __name__ == '__main__':
    
    #User Input and Parsing
    commandLines = []
    N = int(input())
    for i in range(N):
        command, *args = input().split()
        argsList = list(map(int, args))
        commandLines.append([command,argsList])
    
    #After parsing input, we execute the commands
    outputList = []
    for i in commandLines:
        if i[0] == "insert":
            #the insert call inserts integer before specified index.
            #this works even when the list is empty
            outputList.insert(i[1][0], i[1][1])
        elif i[0] == "print":
            #prints list
            print(outputList)
        elif i[0] == "remove":
            #removes the first occurence of the element
            outputList.remove(i[1][0])         
        elif i[0] == "append":
            #appends to the end of the list
            outputList.append(i[1][0])
        elif i[0] == "sort":
            #sorts list
            outputList.sort()
        elif i[0] == "pop":
            #removes element at the end of the list
            outputList.pop()
        elif i[0] == "reverse":
            #reverses list
            outputList.reverse()
        
