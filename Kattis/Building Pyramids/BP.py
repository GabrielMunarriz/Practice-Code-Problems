numberOfBlocks = int(input())
totalPyramidLevels = 0
sideSize = 1
levelSize = 0

while numberOfBlocks >= 0:
    levelSize = sideSize * sideSize
    if numberOfBlocks >= levelSize:
        numberOfBlocks -= levelSize
        totalPyramidLevels += 1
        sideSize += 2
    else:
        break

print(totalPyramidLevels)
