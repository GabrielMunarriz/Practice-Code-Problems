def mutate_string(string, position, character):
    
    stringList = list(string)
    stringList[position] = character
    output = "".join(stringList)
    return output

if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)