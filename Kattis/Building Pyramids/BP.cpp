#include <iostream>
using namespace std;

int main(void) {

    //Initialization
    int numberOfBlocks;
    int totalPyramidLevels = 0;
    int sideSize = 1;
    int levelSize = 0;

    cin >> numberOfBlocks;

    while (numberOfBlocks >=0 ) {

        levelSize = sideSize * sideSize;

        if (numberOfBlocks >= levelSize) {

            numberOfBlocks -= levelSize;
            totalPyramidLevels += 1;
            sideSize +=2;

        } else {

            break;

        }

    }

    cout << totalPyramidLevels;

}