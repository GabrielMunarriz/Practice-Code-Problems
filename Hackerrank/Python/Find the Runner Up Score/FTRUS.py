import math

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    
    #we set maximum to the largest number in arr
    maximum = -math.inf
    for i in range(len(arr)):
        if arr[i] > maximum:
            maximum = arr[i]
    #print(maximum)
    
    #now we find runner up
    runnerUp = -math.inf
    for i in range(len(arr)):
        if arr[i] > runnerUp and arr[i] < maximum:
            runnerUp = arr[i]
    print(runnerUp)
