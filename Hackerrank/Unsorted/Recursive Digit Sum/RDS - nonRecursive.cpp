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
    
    //Initialization AKA the first iteration.
    vector<int> nIntegers;
    for (int i = 0; i <= k - 1; i++) {
            
        for (int j = 0; j <= n.size()-1; j++) {
            
            nIntegers.push_back(int(n[j] - 48));
                
        } 
            
    }
    
    /**
    for (int i = 0; i <= nIntegers.size()-1; i++) {
        
        cout << nIntegers[i] << endl;
        
    }
    **/

    int nInt = 0;
    string nString= "";
    for (int i = 0; i <= nIntegers.size()-1; i++) {
        
        nInt += nIntegers[i];
        
    }
    nString = to_string(nInt);
    int nStringDigits = nString.size();
    //cout << nInt << endl;
    //cout << nString << endl;
    //cout << endl;
    
    // The next iterations are done via this while loop.
    while (nStringDigits > 1) {
        
        //Refreshing nIntegers.
        nIntegers.clear();
        for (int i = 0; i <= nString.size()-1; i++) {

            nIntegers.push_back(int(nString[i] - 48));
            
        }
        
        nInt = 0;
        nString= "";
        //Refreshing nInt and nString
        for (int i = 0; i <= nIntegers.size()-1; i++) {
        
            nInt += nIntegers[i];
        
        }
        nString = to_string(nInt);
        nStringDigits = nString.size();
        
    }
    
    return nInt;

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
