def average(array):
    # your code goes here
    newSet = set(array)
    #print(newSet)
    
    setSum = 0
    setCount = 0
    for i in newSet:
        setSum += i
        setCount += 1
    
    return setSum / setCount
    

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)