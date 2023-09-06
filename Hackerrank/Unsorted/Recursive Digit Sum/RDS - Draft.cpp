#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(string n, int k) {
    
    //Initialization
    vector<int> nIntegers;
    for (int i = 0; i <= n.size()-1; i++) {
        
        nIntegers.push_back(int(n[i] - 48));
        
    }
    int superDigitInt = 0;
    string superDigitString = "";
    
    //Main function
    for (int i = 0; i <= k - 1; i++) {
        
        //before anything, we refresh these values
        superDigitInt = 0;
        superDigitString = "";
        
        //first, we find first superDigit
        for (int j = 0; j <= nIntegers.size()-1; j++) {
            
            superDigitInt += nIntegers[j];
            
        }
        
        cout << i << endl;
        cout << superDigitInt << endl;
        
        //second, we equate superDigitString to superDigitInt;
        superDigitString = to_string(superDigitInt);
        cout << superDigitString << endl;
        
        //third, we clear nIntegers.
        nIntegers.clear();
        
        //fourth, we repopulate nIntegers with new SuperDigitString
        for (int l = 0; l <= superDigitString.size()-1; l++) {
        
            nIntegers.push_back(int(superDigitString[l] - 48));
            
        }
        
        for (int m = 0; m <= nIntegers.size()-1; m++) {
            
            cout << nIntegers[m] << endl;
            
        }
        
        cout << endl;
        
    }
    
    return superDigitInt;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
