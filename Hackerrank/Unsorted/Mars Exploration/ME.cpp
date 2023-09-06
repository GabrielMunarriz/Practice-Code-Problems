#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {

    vector<string> sosMessages;
    //string sosMessage;
    string char1;
    string char2;
    string char3;
    int lettersChanged;
    
    //populating sosMessages
    for (int i = 0; i <= s.size()-1; i+=3) {
        
        char1 = s[i];
        char2 = s[i+1];
        char3 = s[i+2];
        sosMessages.push_back(char1 + char2 + char3);
        
    }
    
    for (int i = 0; i <= sosMessages.size()-1; i++) {
        
        if (sosMessages[i][0] != 'S') {
            
            lettersChanged++;
            
        }
        
        if (sosMessages[i][1] != 'O') {
            
            lettersChanged++;
            
        }
        
        if (sosMessages[i][2] != 'S') {
            
            lettersChanged++;
            
        }
        
    }
    
    return lettersChanged;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
