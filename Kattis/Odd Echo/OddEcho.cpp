#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(void) {

    //Declaring Variables
    int numberOfEntries;
    string currentEntry;
    vector<string> entriesVector; 

    //Taking Input for numberOfEntries
    cin >> numberOfEntries;

    for (int i = 0; i <= numberOfEntries - 1; i++) {

        cin >> currentEntry;
        entriesVector.push_back(currentEntry);

    }

    for (int i = 0; i <= entriesVector.size() - 1; i++) {

        if (i % 2 == 0) {

            cout << entriesVector[i] << endl;

        }

    }

}