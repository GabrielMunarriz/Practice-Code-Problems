if __name__ == '__main__':
    n = int(input())
    
    start = 1
    end = n
    current = 1
    output = ""
    
    for i in range(end):
        output+=str(current)
        current+=1
    
    print(output)