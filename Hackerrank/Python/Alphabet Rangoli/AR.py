def numberToLetter(number):
    letter = ""
    if number == 0:
        letter = "a"
    if number == 1:
        letter = "b"
    if number == 2:
        letter = "c"
    if number == 3:
        letter = "d"
    if number == 4:
        letter = "e"
    if number == 5:
        letter = "f"
    if number == 6:
        letter = "g"
    if number == 7:
        letter = "h"
    if number == 8:
        letter = "i"
    if number == 9:
        letter = "j"
    if number == 10:
        letter = "k"
    if number == 11:
        letter = "l"
    if number == 12:
        letter = "m"
    if number == 13:
        letter = "n"
    if number == 14:
        letter = "o"
    if number == 15:
        letter = "p"
    if number == 16:
        letter = "q"
    if number == 17:
        letter = "r"
    if number == 18:
        letter = "s"
    if number == 19:
        letter = "t"
    if number == 20:
        letter = "u"
    if number == 21:
        letter = "v"
    if number == 22:
        letter = "w"
    if number == 23:
        letter = "x"
    if number == 24:
        letter = "y"
    if number == 25:
        letter = "z"
    
    return letter

#creates a row of letters WITHOUT DASHES
#maxletter is equals to size-1 in this use case
#iteration generates the letterRow at a specific row of the bigger picture
def letterRowGenerator(maxLetter, iteration):
    stack = []
    stackSize = 0
    output = ""
    
    #generates left side.
    #if size = 3, iteration = 1
    #then maxLetter is c and this loop will generate "c-b"
    
    if iteration == 0:
        return numberToLetter(maxLetter)
    
    for i in range(iteration + 1): #Added 1 because i want to include the upper end here
        if i < iteration:
            output += numberToLetter(maxLetter-i) + "-"
            stack.append(numberToLetter(maxLetter-i))
        else:
            output += numberToLetter(maxLetter-i) + "-"
    
    #now we generate right side using stack
    #print("stack")
    #print(stack)

    stackSize = len(stack)
    for i in range(stackSize):
        #we use stackSize because len(stack) changes throughout this loop
        if i < stackSize - 1: 
            output += stack[-1] + "-"
            stack.pop()
        #we use stackSize - 1 because that is the index of the last element of stack
        elif i == stackSize - 1: 
            output += stack[-1]
            stack.pop()
    
    #print("stack after")
    #print(stack)
            
    return output
            
def print_rangoli(size):
    
    stack = []
    dash = "-"
    line = ""
    
    for i in range(size + (size - 1)):
        
        if i < size - 1: #UPPER ROWS
        
            #maxlength = ((2 * (size + (size - 1))) - 1)
            #creates entire row WITH dashes
            print((dash * ((((2 * (size + (size - 1))) - 1)//2) - (i*2))) +
            letterRowGenerator(size - 1, i) +
            (dash * ((((2 * (size + (size - 1))) - 1)//2) - (i*2))))
            
            #store all of this in a stack as well
            stack.append((dash * ((((2 * (size + (size - 1))) - 1)//2) - (i*2))) +
            letterRowGenerator(size - 1, i) +
            (dash * ((((2 * (size + (size - 1))) - 1)//2) - (i*2)))) 
            
        elif i == size - 1: #CENTER ROW
            print(letterRowGenerator(size - 1, i))
            
        elif i > size - 1: #LOWER ROWS
            #now we print based on contents of stack
            print(stack[-1])
            stack.pop()
        

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)