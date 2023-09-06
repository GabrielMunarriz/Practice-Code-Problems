if __name__ == '__main__':
    n = int(input())
    
    start = 0
    end = n
    current = start
    output = []
    
    for i in range(n):
        output.append(current**2)
        current+=1
    
    for i in range(len(output)):
        print(output[i])
    
    
    