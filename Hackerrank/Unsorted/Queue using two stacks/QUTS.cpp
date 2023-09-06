#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    vector<long> queue;
    string input;
    int numberOfQueries;
    string query;
    
    //int queueFunction;
    //int input2;
    //string input3;
    
    //FOR LOOP METHOD WITH CERTAIN NUMBER OF INPUTS
    getline(cin, input); //gets the complete line if delimiter is not specified.
    numberOfQueries = stoi(input);
    
    for(int i = 0; i <= numberOfQueries - 1; i++){
        
        getline(cin, input); //look at the entire line
        query = input;
        
        if (query.substr(0,1) == "1") { //look at first digit only (specifies function)
            
            //cout << "1" << endl;
            queue.push_back(stoul(query.substr(2,query.size()-1))); //enqueues the entire number after space (index 2 until the end of the string)
            //cout << stoi(query.substr(2,2)) << endl;
            //cout << endl;
            
        } else if (query.substr(0,1) == "2") { //look at first digit only (specifies function)
            
            //cout << "2" << endl;
            if (queue.size() > 0) {
                
                queue.erase(queue.begin()); //removes the front
                //cout << queue.front() << endl;
                
            }
            //cout << endl;
            
        } else if (query.substr(0,1) == "3") {//look at first digit only (specifies function)
            
            //cout << "3" << endl;
            cout << queue.front() << endl; //prints the front
            //cout << endl;
            
        }

    }
      
    return 0;
}
