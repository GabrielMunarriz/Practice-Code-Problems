def turnNumberToEnglish_singleDigit(a):
    
    #numberOfDigits = len(a)
    number = int(a)
    stringEquivalent = ''

    if number == 0:

        stringEquivalent = 'zero'

    elif number == 1:

        stringEquivalent = 'one'
    
    elif number == 2:

        stringEquivalent = 'two'
    
    elif number == 3:

        stringEquivalent = 'three'
    
    elif number == 4:

        stringEquivalent = 'four'
    
    elif number == 5:

        stringEquivalent = 'five'
    
    elif number == 6:

        stringEquivalent = 'six'
    
    elif number == 7:

        stringEquivalent = 'seven'
    
    elif number == 8:

        stringEquivalent = 'eight'
    
    elif number == 9:

        stringEquivalent = 'nine'

    return stringEquivalent


def turnNumberToEnglish(a):
    
    #numberOfDigits = len(a)
    firstNumber = int(a[0])
    secondNumber = int(a[1])
    stringEquivalent = ''

    if firstNumber == 0:

        stringEquivalent = turnNumberToEnglish_singleDigit(secondNumber)

    elif firstNumber == 1:

        if secondNumber == 1:

            stringEquivalent = 'eleven'
        
        elif secondNumber == 2:

            stringEquivalent = 'twelve'
        
        elif secondNumber == 3:

            stringEquivalent = 'thirteen'
        
        elif secondNumber == 4:

            stringEquivalent = 'fourteen'
        
        elif secondNumber == 5:

            stringEquivalent = 'fifteen'
        
        elif secondNumber == 6:

            stringEquivalent = 'sixteen'
        
        elif secondNumber == 7:

            stringEquivalent = 'seventeen'
        
        elif secondNumber == 8:

            stringEquivalent = 'eighteen'
        
        elif secondNumber == 9:

            stringEquivalent = 'nineteen'
    
    elif firstNumber == 2:

        if secondNumber == 0:
        
            stringEquivalent = 'twenty'
        
        else:

            stringEquivalent = 'twenty-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 3:

        if secondNumber == 0:
        
            stringEquivalent = 'thirty'
        
        else:

            stringEquivalent = 'thirty-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 4:

        if secondNumber == 0:
        
            stringEquivalent = 'forty'
        
        else:

            stringEquivalent = 'forty-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 5:

        if secondNumber == 0:
        
            stringEquivalent = 'fifty'
        
        else:

            stringEquivalent = 'fifty-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 6:

        if secondNumber == 0:
        
            stringEquivalent = 'sixty'
        
        else:

            stringEquivalent = 'sixty-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 7:

        if secondNumber == 0:
        
            stringEquivalent = 'seventy'
        
        else:

            stringEquivalent = 'seventy-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 8:

        if secondNumber == 0:
        
            stringEquivalent = 'eighty'
        
        else:

            stringEquivalent = 'eighty-' + turnNumberToEnglish_singleDigit(secondNumber)
    
    elif firstNumber == 9:

        if secondNumber == 0:
        
            stringEquivalent = 'ninety'
        
        else:

            stringEquivalent = 'ninety-' + turnNumberToEnglish_singleDigit(secondNumber)

    return stringEquivalent


userInput = input()
splitUserInput = userInput.split()
output = ''

#print(splitUserInput)

for i in range(len(splitUserInput)):

    #print(splitUserInput[i].isnumeric())

    temporaryString = ''

    if(splitUserInput[i].isnumeric()):

        if len(splitUserInput[i]) == 1:

            temporaryString = turnNumberToEnglish_singleDigit(splitUserInput[i])
        
        elif len(splitUserInput[i]) == 2: 

            temporaryString = turnNumberToEnglish(splitUserInput[i])


        if i == 0:

            output += temporaryString.capitalize() + ' '
        
        else:

            output += temporaryString + ' '

    else: 
    
        output += splitUserInput[i] + ' '

print(output)

    


