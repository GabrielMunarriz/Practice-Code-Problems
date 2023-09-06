#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string input;
    string inputOperation;
    string inputType;
    string inputName;
    string output;
    bool upperCaseNext;

    while (getline(cin, input, '\n')) {
        
        inputOperation = input[0];
        inputType = input[2];
        inputName = input.substr(4, input.size()-1);
        output = "";
        upperCaseNext = false;
        
        if (inputOperation == "S") {
            
            for(int i = 0; i <= inputName.size()-1; i++) {
                
                if(inputName[i] == '(' || input[i] == ')' ) {
                    
                    continue;
                    
                } else if(isupper(inputName[i])) {
                    
                    if (i == 0) {
                        
                        output += tolower(inputName[i]);
                        
                    } else {
                        
                        output += " ";
                        output += tolower(inputName[i]);
                        
                    }
                    
                    
                } else {
                    
                    output += inputName[i];
                    
                }
                
            }
            
        }
        
        if (inputOperation == "C") {
            
            for (int i = 0; i <= inputName.size()-1; i++) {
                
                if(inputType == "M") {
                
                    if(inputName[i] == ' ') {
                        
                        upperCaseNext = true;
                        
                    } else {
                        
                        if (upperCaseNext) {
                            
                            output += toupper(inputName[i]);
                            upperCaseNext = false;
                            
                        } else {
                            
                            output += inputName[i];
                            
                        }
                        
                    }
                    
                    if (i == inputName.size()-1) {
                        
                        output += "()";
                        
                    }

                } else if(inputType == "C") {
                    
                    if(i == 0) {
                        
                        output += toupper(inputName[i]);
                        
                    } else {
                        
                        if(inputName[i] == ' ') {
                        
                        upperCaseNext = true;
                        
                        } else {
                            
                            if (upperCaseNext) {
                                
                                output += toupper(inputName[i]);
                                upperCaseNext = false;
                                
                            } else {
                                
                                output += inputName[i];
                                
                            }
                            
                        }
                        
                    }
                    
                } else if (inputType == "V") {
                    
                    if(inputName[i] == ' ') {
                        
                        upperCaseNext = true;
                        
                    } else {
                        
                        if (upperCaseNext) {
                            
                            output += toupper(inputName[i]);
                            upperCaseNext = false;
                            
                        } else {
                            
                            output += inputName[i];
                            
                        }
                        
                    }

                }
                
            }
            
            
            
        }
        
        //cout << inputOperation << " " << inputType << " " << inputName << endl;
        cout << output << endl;
    }
      
    return 0;
}
