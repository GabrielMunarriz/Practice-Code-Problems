#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solveOLD(s): #this works BUT it does not preserve white spaces in output
    
    output = ""
    
    #add strings into a list
    stringList = s.split()
    
    #add characters of each string into its own list, which are all in a list
    stringCharList = []
    for i in stringList:
        stringCharList.append(list(i))
    
    #now we capitalize
    for i in stringCharList:
        i[0] = i[0].upper()
    
    print(stringCharList)
        
    #now we turn em back to strings

    for i in stringCharList:
        for j in i:
            output += j
        output += " "
    
    print(output)
        
    return output

def solve(s):
    
    output = ""
    
    #add all characters into a list
    stringCharList = list(s)
    
    #now we capitalize
    for i in range(len(stringCharList)):
        #A character is the start of a word if...
        #1. it is the very first character in the string AND it is alphabetical
        #2. it is a character right after a whitespace and it is alphabetical
        if (i == 0 and stringCharList[i].isalpha()) or (stringCharList[i-1] == " " and stringCharList[i].isalpha()):
            stringCharList[i] = stringCharList[i].upper()
    
    print(stringCharList)
        
    #now we turn em back to strings

    for i in stringCharList:
        output += i
    
    print(output)
        
    return output

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()
