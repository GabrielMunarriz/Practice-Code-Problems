#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    
    //initialization
    string output = s;
    //we want k to only be from 1-26 since 27-52 and so on (the next 26 numbers) maps to the same letters anyway.
    int simplifiedK = k; 
    while (simplifiedK >= 27) {
            
            simplifiedK -= 26;
            
    }
    
    cout << simplifiedK << endl;
    
    //We go through each letter in the string
    for (int i = 0; i <= output.size()-1; i++) {
        
        //we find out if the letter is uppercase or lowercase
        if (output[i] >= 65 && output[i] <= 90) { //uppercase Letters
            
            //afterwards, we check if it exceeds the ascii code for Z
            //We check first before we increment because if we increment first, we might end up including invalid ascii codes that we can't modify later on.
            if (output[i] + simplifiedK > 90) {
                
                //if the character exceeds Z, we first increment output[i] by simplifiedK then subtract by 26 to get the code of the letter the character would be mapped to if Z "looped back" to A.
                output[i] = static_cast<char>(output[i] + simplifiedK - 26);
                
            } else {
                
                //we increment the letter by the value of simplifiedK
                output[i] = static_cast<char>(output[i] + simplifiedK);
                
            }
            
        } else if (output[i] >= 97 && output[i] <= 122) {//lowercase Letters
        
            //afterwards, we check if it exceeds the ascii code for z
            //We check first before we increment because if we increment first, we might end up including invalid ascii codes that we can't modify later on.
            if (output[i] + simplifiedK > 122) {
                
                //if the character exceeds z, we first increment output[i] by simplifiedK then subtract by 26 to get the code of the letter the character would be mapped to if z "looped back" to a.
                output[i] = static_cast<char>(output[i] + simplifiedK - 26);
                
            } else {
                
                //we increment the letter by the value of simplifiedK
                output[i] = static_cast<char>(output[i] + simplifiedK);
                
            }
            
            
        } else {
            
            //we skip dashes and any other kind of character
            continue;
            
        }
        
            
    }
    
    return output;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

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
