#these "generate" functions convert decimal to a different format AND adds spacing.

def generate_decimal(number, length):
    
    #Convert Decimal to Decimal (no change but it's a string now)
    decimal = str(number)
    
    #Add Spaces
    for i in range(length - len(decimal)):
        decimal = " " + decimal
    
    return decimal

def generate_binary(number, length):
    
    #Convert Decimal to Binary
    binary = ""
    while number != 0:
        binary = str(number % 2) + binary
        number //= 2
        
    #Add Spaces
    for i in range(length - len(binary)):
        binary = " " + binary
        
    return binary

#This function does not add padding.
def generate_binary_noPad(number):
    
    #Convert Decimal to Binary
    binary = ""
    while number != 0:
        binary = str(number % 2) + binary
        number //= 2
    return binary

def generate_octal(number, length):
    
    #Convert Decimal to Octal
    octal = ""
    while number != 0:
        octal = str(number % 8) + octal
        number //= 8
    
    #Add Spaces
    for i in range(length - len(octal)):
        octal = " " + octal
    
    return octal

def hexadecimal_remainder_assignment(number):
    
    output = ""
    if number < 10:
        output += str(number)
    elif number == 10:
        output += "A"
    elif number == 11:
        output += "B"
    elif number == 12:
        output += "C"
    elif number == 13:
        output += "D"
    elif number == 14:
        output += "E"
    elif number == 15:
        output += "F"    
    
    return output
    
def generate_hexadecimal(number, length):
    
    #Convert Decimal to Hexadecimal
    hexadecimal = ""
    while number != 0:
        hexadecimal = hexadecimal_remainder_assignment(number % 16) + hexadecimal
        number //= 16
        
    #Add Spaces
    for i in range(length - len(hexadecimal)):
        hexadecimal = " " + hexadecimal
        
    return hexadecimal

def print_formatted(number):

    for i in range(number):
        print(generate_decimal(i+1, len(generate_binary_noPad(number))) + " " 
        + generate_octal(i+1, len(generate_binary_noPad(number))) + " " 
        + generate_hexadecimal(i+1, len(generate_binary_noPad(number))) + " " 
        + generate_binary(i+1, len(generate_binary_noPad(number))))
    

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)