import math

if __name__ == '__main__':
    
    records = []
    for i in range(int(input())):
        name = input()
        score = float(input())
        newRecord = [name, score]
        records.append(newRecord)
    
    #first, find lowest score
    minimum = math.inf #initialized to the highest number possible
    for i in range(len(records)):
        if records[i][1] < minimum:
            minimum = records[i][1]
    #print(minimum)
    
    #next, find second to the lowest score
    secondToLowest = math.inf #initialized to the highest number possible
    for i in range(len(records)):
        if records[i][1] < secondToLowest and records[i][1] > minimum:
            secondToLowest = records[i][1]
    #print(secondToLowest)
    
    #we then create the output list of names with the second to the lowest score
    output = []
    for i in range(len(records)):
        if records[i][1] == secondToLowest:
            output.append(records[i][0])
    output.sort()
    
    #we then print the names
    for i in output:
        print(i)
    