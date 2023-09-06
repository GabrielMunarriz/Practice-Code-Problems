# Enter your code here. Read input from STDIN. Print output to STDOUT

n, m = map(int, input().split())

dash = "-"
pattern = ".|."
welcome = "WELCOME"
stack = []

for i in range(n):
    if i < n//2:
        stack.append( (dash*(((m-len(pattern*(i+i+1)))//2))) + (pattern*(i+i+1)) + (dash*(((m-len(pattern*(i+i+1)))//2))) )
        print( (dash*(((m-len(pattern*(i+i+1)))//2))) + (pattern*(i+i+1)) + (dash*(((m-len(pattern*(i+i+1)))//2))) )
    elif i == n//2:
        print( (dash*(((m-len(welcome))//2))) + welcome + (dash*(((m-len(welcome))//2))) )
    elif i > n//2:
        print(stack[-1])
        stack.pop()


#print((dash*(((m-len(pattern*(i+i+1)))//2))))
