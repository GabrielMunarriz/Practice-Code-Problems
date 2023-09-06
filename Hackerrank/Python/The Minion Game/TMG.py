#WORKS but UNOPTIMIZED

def isVowel(character):
    
    output = False
    
    if character == "a" or character == "A" or character == "e" or character == "E" or character == "i" or character == "I" or character == "o" or character == "O" or character == "u" or character == "U":
        output = True
        
    return output
        

def minion_game(string):
    # your code goes here
    
    stuartScore = 0
    kevinScore = 0
    
    for i in range (1, len(string) + 1): #we iterate through substring LENGTHS in this outer loop so we start from 1.
    
        if i == 1:
            for j in string: #iterate through characters 1 by 1
                if isVowel(j):
                    kevinScore += 1
                else:
                    stuartScore += 1
        
        else: #iterate through characters 2 by 2, 3 by 3, so on
            for j in range(len(string) - i + 1): #e.g. if we are looking at 2-length substr, we stop iterating 2 letters before the end
                tempString = string[j:j+i-1]
                if isVowel(tempString[0]):
                    kevinScore += 1
                else:
                    stuartScore += 1
                    
    #print(stuartScore)
    #print(kevinScore)
    
    if stuartScore > kevinScore:
        print("Stuart " + str(stuartScore))
    elif stuartScore < kevinScore:
        print("Kevin " + str(kevinScore))
    elif stuartScore == kevinScore:
        print("Draw")
    

if __name__ == '__main__':
    s = input()
    minion_game(s)