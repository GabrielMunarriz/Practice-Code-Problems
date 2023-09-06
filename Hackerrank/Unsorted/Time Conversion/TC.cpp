#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {

    string hour;
    int hourInt;
    string minutes;
    string seconds;
    string AMorPM;
    string convertedTime;
    string temporaryString0;
    string temporaryString1;
    
    temporaryString0 = s[0];
    temporaryString1 = s[1];
    hour = temporaryString0 + temporaryString1;
    //cout << hour << endl;
    
    temporaryString0 = s[3];
    temporaryString1 = s[4];
    minutes = temporaryString0 + temporaryString1;
    //cout << minutes << endl;
    
    temporaryString0 = s[6];
    temporaryString1 = s[7];
    seconds = temporaryString0 + temporaryString1;
    //cout << seconds << endl;
    
    temporaryString0 = s[8];
    temporaryString1 = s[9];
    AMorPM = temporaryString0 + temporaryString1;
    //cout << AMorPM << endl;
    
    hourInt = stoi(hour);
    if (AMorPM == "PM") {
        
        if (hourInt == 12) {
            
            hour = "12";
            
        } else {
            
            hourInt += 12;
            hour = to_string(hourInt);
            
        }
        
    }
    
    
    if (AMorPM == "AM") {
        
        if (hourInt == 12) {
            
            hour = "00";
            
        }     
        
    }
    
    convertedTime = hour + ":" + minutes + ":" + seconds;
    
    return convertedTime;
    
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