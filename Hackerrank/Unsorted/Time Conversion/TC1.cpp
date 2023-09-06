#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    string output;
    
    if (s.substr(8,2) == "AM") {
        
        if (s.substr(0,2) == "12") {
            
            output = "00" + s.substr(2,3) + s.substr(5,3);
            cout << "00" << s.substr(2,3) << s.substr(5,3) << endl;
            
        } else {
            
            output = s.substr(0,2) + s.substr(2,3) + s.substr(5,3);
            cout << s.substr(0,2) << s.substr(2,3) << s.substr(5,3) << endl;
            
        }
        
    } else {
        
        int convertedHour = stoi(s.substr(0,2)) + 12;
        
        if (s.substr(0,2) == "12") {
            
            output = "12" + s.substr(2,3) + s.substr(5,3);
            cout << "12" << s.substr(2,3) << s.substr(5,3) << endl;
            
        } else {
            
            output = to_string(convertedHour) + s.substr(2,3) + s.substr(5,3);
            cout << to_string(convertedHour) << s.substr(2,3) << s.substr(5,3) << endl;
            
        }
        
    }
    
    return output;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
