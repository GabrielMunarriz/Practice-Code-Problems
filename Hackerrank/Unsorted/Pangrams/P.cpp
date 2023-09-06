#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {

    string result;
    vector<char> unusedLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    for (int i = 0; i <= s.size()-1; i++) {
        
        //cout << "s[" << i << "]: " << s[i] << endl; 
        
        if (unusedLetters.size() == 0) {
            
            break;
            
        }
        
        if (s[i] == ' ') {
            
            continue;
            
        }
        
        for (int j = 0; j <= unusedLetters.size()-1; j++) {
            
            if (tolower(s[i]) == unusedLetters[j]) {
                
                //cout << "removing " << unusedLetters[j] << endl;
                unusedLetters.erase(unusedLetters.begin()+j);
                break;
                
            }
            
        }
        
    }
    
    if (unusedLetters.size() == 0) {
        
        result = "pangram";
        
    } else {
        
        result = "not pangram";
        
    }
    
    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
