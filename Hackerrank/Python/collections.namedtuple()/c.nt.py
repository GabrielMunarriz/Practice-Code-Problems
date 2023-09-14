# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import namedtuple

testCases = int(input())
columns = input().split()
Student = namedtuple('Student', columns)

runningSum = 0
runningCount = 0

for i in range(testCases):
    col1, col2, col3, col4 = input().split()
    studentEntry = Student(col1, col2, col3, col4)
    runningSum += int(studentEntry.MARKS)
    runningCount += 1
    
average = runningSum/runningCount
print(average)
    
