if __name__ == '__main__':
    n = int(input())
    outputTuple = tuple(map(int, input().split()))
    print(hash(outputTuple))