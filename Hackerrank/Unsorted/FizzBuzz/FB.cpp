#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    
    //Initialization
    bool divisibleBy3 = false;
    bool divisibleBy5 = false;
    //vector<int> nDigits;
    
    //-- Checking Divisibility by 3 -- 
    //(LOL I TRIED TO CHECK DIVISIBILITY USING THE MATH WAY BUT I FORGOT I COULD JUST USE MOD. EITHER WAY THESE ALGOS MIGHT BE USEFUL.)
    

    //Finding the number of digits in a number
    //int nNumberOfDigits = 0;
    //int temporaryNumber = n;
    //while(temporaryNumber != 0) {
        //temporaryNumber /= 10;
        //nNumberOfDigits ++;
    //}
    
    //cout << "nNumberOfDigits: " << nNumberOfDigits << endl;
    
    //Adding each digit into a vector
    //temporaryNumber = n;
    //int lastDigitTempNumber;
    //for(int i = nNumberOfDigits; i > 0; i--) {
        
        //lastDigitTempNumber = temporaryNumber % 10;
        //cout << lastDigitTempNumber << endl;
        //nDigits.push_back(lastDigitTempNumber);
        //temporaryNumber /= 10;
        //cout << temporaryNumber << endl;
        
    //}
    
    //We then add each digit in the vector
    //int sumOfAllDigits = accumulate(nDigits.begin(), nDigits.end(), 0);
    

    
    for (int i = 1; i <= 15; i++) {
        
        divisibleBy3 = false;
        divisibleBy5 = false;
        
        if (i % 3 == 0) {
        
            divisibleBy3 = true;
        
        }
        
        if (i % 5 == 0) {
        
            divisibleBy5 = true;
        
        }
        
        if (divisibleBy3 == true && divisibleBy5 == true) {
        
            cout << "FizzBuzz" << endl;
            
        } else if (divisibleBy3 == true && divisibleBy5 != true) {
            
            cout << "Fizz" << endl;
            
        } else if (divisibleBy3 != true && divisibleBy5 == true) {
            
            cout << "Buzz" << endl;
            
        } else if (divisibleBy3 != true && divisibleBy5 != true) {
            
            cout << i << endl;
            
        }
        
    }

    
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    fizzBuzz(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}