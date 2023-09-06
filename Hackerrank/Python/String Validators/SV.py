if __name__ == '__main__':
    s = input()
    
    alphanumeric = False
    alphabetical = False
    digit = False
    lowerCase = False
    upperCase = False
    
    for i in s:
        
        if i.isalnum():
            alphanumeric = True

        if i.isalpha():
            alphabetical = True
        
        if i.isdigit():
            digit = True
            
        if i.islower():
            lowerCase = True
        
        if i.isupper():
            upperCase = True

    print(alphanumeric)
    print(alphabetical)
    print(digit)
    print(lowerCase)
    print(upperCase)
    
