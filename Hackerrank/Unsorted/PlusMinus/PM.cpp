#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {

    float zeros = 0.00;
    float positives = 0.00;
    float negatives = 0.00;
    float zerosRatio = 0.00;
    float positivesRatio = 0.00;
    float negativesRatio = 0.00;

    for (int i = 0; i <= arr.size()-1; i++) {
        
        if (arr[i] == 0.00) {
            
            zeros += 1.00;
            
        } else if (arr[i] > 0.00) {
            
            positives += 1.00;
            
        } else if (arr[i] < 0.00) {
            
            negatives += 1.00;
            
        }
        
    }
    
    zerosRatio = zeros / arr.size();
    positivesRatio = positives / arr.size();
    negativesRatio = negatives / arr.size();
    
    cout << setprecision(6) << positivesRatio << endl;
    cout << setprecision(6) << negativesRatio << endl;
    cout << setprecision(6) << zerosRatio << endl;
    
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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
