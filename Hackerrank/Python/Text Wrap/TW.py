import textwrap

def wrap(string, max_width):
    
    stringList = list(string)
    
    j = 0
    i = 0
    stringListCurrentLength = len(stringList)
    while i < stringListCurrentLength:
        if j == max_width:
            stringList.insert(i,"\n")
            stringListCurrentLength = len(stringList)
            j = 0
        else:
            j += 1
        i += 1
    
    output = "".join(stringList)

    return output

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)