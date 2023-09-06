# Enter your code here. Read input from STDIN. Print output to STDOUT

import calendar

month, day, year = map(int, input().split())

if (calendar.weekday(year, month, day) == 0):
    print("MONDAY")
elif (calendar.weekday(year, month, day) == 1):
    print("TUESDAY")
elif (calendar.weekday(year, month, day) == 2):
    print("WEDNESDAY")
elif (calendar.weekday(year, month, day) == 3):
    print("THURSDAY")
elif (calendar.weekday(year, month, day) == 4):
    print("FRIDAY")
elif (calendar.weekday(year, month, day) == 5):
    print("SATURDAY")
elif (calendar.weekday(year, month, day) == 6):
    print("SUNDAY")