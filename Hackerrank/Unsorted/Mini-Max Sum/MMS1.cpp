#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    
    //cout << "test" << endl;

    vector<long> longVector;
    long minSum;
    long maxSum;
    long currentSum = 0;
    long currentIndex = 0;
    
    //sorting arr - unnecessary apparently.
    //sort(arr.begin(), arr.end());
    
    //adding and converting everything in arr to longVector
    for (int i = 0; i <= arr.size()-1; i++) {
        
        longVector.push_back((long)arr[i]);
        
    }

    // for (int i = 0; i <= longVector.size()-1; i++) {

    //     cout << longVector[i] << endl;

    // }
    
    //sum all numbers except longVector[i] then update maxSum and minSum
    for (int i = 0; i <= longVector.size()-1; i++) {
        
        //force refresh
        currentSum = 0;
        
        //this loop sums all numbers after longVector[i]

        for (int j = i + 1; j <= longVector.size()-1; j++) {
            
            currentSum += longVector[j];
            
        }
        
        //this loop sums all numbers before longVector[i]
        for (int j = i - 1; j >= 0; j--) {
            
            currentSum += longVector[j];
            
        }

        //cout << currentSum << endl;
        
        if (i == 0) {

            maxSum = currentSum;
            minSum = currentSum;

        } else {

            if (currentSum >= maxSum) {
            
                maxSum = currentSum;
            
            }
            
            if (currentSum <= minSum) {
                
                minSum = currentSum;
                
            }

        }
        
    }
    
    //print statement
    cout << minSum << " " << maxSum << endl;

}

int main()
{

    //Instantiation
    //string input;
    string userInput;
    string currentlyStreamed;
    string output;
    vector<int> numbersVector;

    getline(cin, userInput);

    istringstream inputStringStream(userInput);

    while (inputStringStream) {

        inputStringStream >> currentlyStreamed;

        if (inputStringStream) {
            
            numbersVector.push_back(stoi(currentlyStreamed));

        }

    }

    // for (int i = 0; i <= numbersVector.size()-1; i++) {

    //     cout << numbersVector [i] << endl;

    // }

    miniMaxSum(numbersVector);

}
