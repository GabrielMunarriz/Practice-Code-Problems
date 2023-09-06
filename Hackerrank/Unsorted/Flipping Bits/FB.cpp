#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {
    
    long runningN = n;
    vector<long> binaryConversion;
    vector<long> flippedBinaryConversion;
    vector<long> binaryToDecimalDigits;
    long result = 0;
    
    
    //Find 32-Bit Binary and store each bit in a vector
    //runningN = n;
    while (runningN > 0) {
        
        //cout << runningN << endl;
        binaryConversion.insert(binaryConversion.begin(), runningN % 2);
        runningN = runningN/2;
        
    }
    
    for (int i = binaryConversion.size()-1 ; i < 31; i++) {
        
        binaryConversion.insert(binaryConversion.begin(), 0);
        
    }
    
    //Flip Beach bit in the vector
    for (int i = 0; i <= binaryConversion.size()-1; i++) {
        
        if (binaryConversion[i] == 0) {
            
            flippedBinaryConversion.push_back(1);
            
        } else {
            
            flippedBinaryConversion.push_back(0);
            
        }
        
    }
    
    //Convert Binary to Decimal
    //Multiplying each bit with 2^x where x is its decimal place or something
    for (int i = 0; i <= flippedBinaryConversion.size()-1; i++) {
        
        binaryToDecimalDigits.push_back(flippedBinaryConversion[i] * pow(2, flippedBinaryConversion.size()-1-i));
        
    }
    
    //Add all the numbers together
    for (int i = 0; i <= binaryToDecimalDigits.size()-1; i++) {
        
        result += binaryToDecimalDigits[i];
        
    }
    
    //cout
    // for (int i = 0; i <= binaryConversion.size()-1; i++) {
        
    //     cout << binaryConversion[i];
        
    // }
    
    // cout << endl;
    
    // for (int i = 0; i <= flippedBinaryConversion.size()-1; i++) {
        
    //     cout << flippedBinaryConversion[i];
        
    // }
    
    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

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
