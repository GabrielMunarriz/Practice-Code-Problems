#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    
    string output = "";
    stack<string> bracketsStack;
    unordered_map<string,string> bracketPairs;
    bracketPairs[")"] = "(";
    bracketPairs["]"] = "[";
    bracketPairs["}"] = "{";
    bool balanced = true;
    //cout << bracketPairs["]"];
    
    for (int i = 0; i <= s.size()-1; i++) {
        
        if (s.substr(i,1) == "(" || s.substr(i,1) == "[" || s.substr(i,1) == "{") {
            
            bracketsStack.push(s.substr(i,1));
            
        } else if (s.substr(i,1) == ")" || s.substr(i,1) == "]" || s.substr(i,1) == "}") {
            
            if (bracketsStack.empty()) {
                
                balanced = false;
                break;
                
            }
            
            if (bracketsStack.top() == bracketPairs[s.substr(i,1)]) {
                
                bracketsStack.pop();
                
            } else {
                
                balanced = false;
                break;
                
            }
            
        }
        
    }    
    
    if (bracketsStack.empty() && balanced == true) {
        
        output = "YES";
        
    } else {
        
        output = "NO";
        
    }
    
    return output;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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
