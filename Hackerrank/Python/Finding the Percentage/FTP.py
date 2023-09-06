if __name__ == '__main__':
    
    n = int(input())
    student_marks = {}
    
    #parse input
    for _ in range(n):
        
        #first element in input is name, the rest is 
        #part of a new list called line
        name, *line = input().split()
        #print(line)
        
        #turn line into a list of floats instead of strings
        scores = list(map(float, line))
        
        #create a new entry in student_marks dictionary. the key "name" will be
        #mapped into the value "scores", which is a list of floats
        student_marks[name] = scores
    
    #initialize query
    query_name = input()
    query_scores = student_marks[query_name]
    
    
    #Find the average
    #first, add all query_scores
    average = 0
    for i in range(len(query_scores)):
        average += query_scores[i]
    #second, divide sum by the number of scores
    average = average / len(query_scores)
    
    #print average rounded to 2 decimal places
    print("%.2f" % average)
        