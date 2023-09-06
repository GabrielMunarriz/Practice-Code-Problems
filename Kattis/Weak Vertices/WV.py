def look_for_connection(connectionList, targetConnection):

    numberExists = False

    for i in range(len(connectionList)):
        if connectionList[i] == targetConnection:
            numberExists = True

    return numberExists

def node_combinations(connectionList):

    if (len(connectionList) == 0) or (len(connectionList) == 1) :

        return -1



allAdjacencyMatricesList = []

# Parses data. Adds matrix into lists.
while True:

    numberOfVertices = int(input())
    newAdjacencyMatrixList = []

    if numberOfVertices == -1:

        break

    for i in range(numberOfVertices):

        adjacencyMatrixRow = input()
        splitAdjacencyMatrixRow = adjacencyMatrixRow.split()
        newAdjacencyMatrixList.append(splitAdjacencyMatrixRow)
    
    allAdjacencyMatricesList.append(newAdjacencyMatrixList)

print(allAdjacencyMatricesList)


# Lists all connections of each node
allConnectionsList = []

for i in range(len(allAdjacencyMatricesList)): # Looking at all graph adjacency matrices

    currentGraphCollectionsList = []

    for j in range(len(allAdjacencyMatricesList[i])): #Looking at adjacency matrix of graph i

        currentNodeConnectionsList = []

        for k in range(len(allAdjacencyMatricesList[i][j])): #Looking at node j of graph i

            if int(allAdjacencyMatricesList[i][j][k]) == 1: #looking at each digit k (which is either 0 or 1), from node j, from graph i

                currentNodeConnectionsList.append(k) 
        
        currentGraphCollectionsList.append(currentNodeConnectionsList)
    
    allConnectionsList.append(currentGraphCollectionsList)

print(allConnectionsList)

# print(look_for_connection(allConnectionsList[0][1], 2))


for i in range(len(allConnectionsList)): # All Graph Connections
    
    for j in range (len(allConnectionsList[i])): # All Connections in Graph i

#         for k in range (len(allConnectionsList[i][j])):







            


