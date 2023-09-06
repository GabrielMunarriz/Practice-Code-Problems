#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(vector<int> a) {
    
    //vector<int> hasMatch;
    bool matchFound = false;
    int output;

    for (int i = 0; i <= a.size()-1; i++) {
        
        matchFound = false; //reset matchFound flag
        cout << "i = " << i << endl;
        cout << "a[i] = " << a[i] << endl;
        
        //Check all elements to the right of a[i] EXCEPT last element
        if (i != a.size()-1) {
            
            for (int j = i + 1; j <= a.size()-1; j++) {
            
                if (a[i] == a[j]) {
                    
                    //hasMatch.push_back(a[i]);
                    cout << "rightside match found" << endl;
                    matchFound = true;
                    break;
                
                }
            
            }
            
        }
        
        //Check all elements to the left of a[i] EXCEPT first element
        //Check if rightside match is still false. If there is a rightside match, then there is definitely no leftside match.
        if (i != 0 && matchFound == false) {
            
            for (int k = i - 1; k >= 0; k--) {
                
                if (a[i] == a[k]) {
                    
                    //hasMatch.push_back(a[i]);
                    cout << "leftside match found" << endl;
                    matchFound = true;
                    break;
                    
                }
                
            }
        
        }
        
        //if matchFound is still false, then we found our unique element.
        if(matchFound == false) {
            
            output = a[i];
            break;
            
        }
        
    }
    
    /**
    for (int i = 0; i <= hasMatch.size()-1; i++) {
        
        cout << hasMatch[i] << endl;
        
    }
    **/
    
    return output;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = lonelyinteger(a);

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
