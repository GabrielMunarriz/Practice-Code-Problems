#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    string currentText = "";
    stack<string> currentTextHistory;
    string input;
    int numberOfOperations;
    string operation;
    int charactersToDelete;
    
    getline(cin, input); //gets the complete line if delimiter is not specified.
    numberOfOperations = stoi(input);
    
    for(int i = 0; i <= numberOfOperations - 1; i++){
        
        getline(cin, input); //look at the entire line
        operation = input;
        
        if (operation.substr(0,1) == "1") { //look at first digit only (specifies function)
            
            currentText += operation.substr(2,operation.size()-1);
            currentTextHistory.push(currentText);
            
        } else if (operation.substr(0,1) == "2") { 
            
            if (currentText.size() <= stoi(operation.substr(2,operation.size()-1))) {
                
                charactersToDelete = currentText.size();
                
            } else {
                
                charactersToDelete = stoi(operation.substr(2,operation.size()-1));
                
            }
            for (int j = 0; j <= charactersToDelete - 1; j++) {
                
                currentText.pop_back();
                
            }
            currentTextHistory.push(currentText);
            
        } else if (operation.substr(0,1) == "3") { 
            
            if (currentText.size() >= stoi(operation.substr(2,operation.size()-1))) {
                
                cout << currentText[stoi(operation.substr(2,operation.size()-1))-1] << endl;
                
            }
             
            /**
            we subtract 1 to the index of currentText because we want to map the argument 
            1 to index 0 and so on.
            **/
            
        } else if (operation.substr(0,1) == "4") { 
            
            currentTextHistory.pop();
            if (currentTextHistory.empty()) {
                
                currentText = "";
                
            } else {
                
                currentText = currentTextHistory.top();
                
            }
            
        }

    }
    
    //DEBUGGING
    /**
    cout << currentText << endl;
    
    int currentTextHistoryInitialStackSize = currentTextHistory.size();
    for (int i = 0; i <= currentTextHistoryInitialStackSize-1; i++) {
        
        cout << "i = " << i << " " << currentTextHistory.top() << " size: " << currentTextHistory.size() <<  endl;
        currentTextHistory.pop();
        
    }
    **/
       
    return 0;
    
}
