#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
 
 
//My Solution
/**
We sort each queue like this (Bubble Sort)
 
1 2 5 3 7 8 6 4
1 2 3 5 7 6 4 8    | 3 swaps | 5 swapped once. 8 swapped twice.
1 2 3 5 6 4 7 8    | 2 swaps | 7 swapped twice.
1 2 3 5 4 6 7 8    | 1 swap | 6 swapped once.
1 2 3 4 5 6 7 8    | 1 swap | 5 swapped once.

and we count the swaps for leastBribesNecessary

How do we find "too chaotic"?

We can count how much a person has bribed someone by counting how much the lefthand number
has been swapped.

**/
void minimumBribes(vector<int> q) {
    
    int leastBribesNecessary = 0; //AKA total bribes done by all people.
    bool tooChaoticFlag = false;
    
    //Creating Frequency Table for each element of q.
    vector<int> qElementFrequency;
    for (int i = 0; i <= q.size(); i++) { 
    // Will create a vector with q.size() + 1 number of zeros (+1 is there because it includes 0 itself.)
        
        qElementFrequency.push_back(0);
        
    }
    /**
    for (int i = 0; i <= qElementFrequency.size()-1; i++) {
        
        cout << qElementFrequency[i] << " ";
        
    }
    cout << endl;
    **/
    
    bool sorted = false;
    while (sorted == false) {
        
        sorted = true; //this is the "breakout" statment
        
        for (int i = 0; i <= q.size() - 2; i++) { 
        
        /**
        the minus 2 is here because the "lefthand" number only goes up until 
        the 2nd to the last element. the last element can't be the "lefthand" number.
        **/
        
            if (q[i] > q[i+1]) {
                
                leastBribesNecessary++;
                qElementFrequency[q[i]]++; 
                swap(q[i], q[i+1]);
                sorted = false;
                
            }
            
        }
        
    }
    
    for (int i = 0; i <= qElementFrequency.size()-1; i++) {
        
        //cout << qElementFrequency[i] << " ";
        
        if (qElementFrequency[i] > 2) {
            
            tooChaoticFlag = true;
            break;
            
        }
        
    }
    //cout << endl;
    
    if (tooChaoticFlag == true) {
        
        cout << "Too chaotic" << endl;
        
    } else {
        
        cout << leastBribesNecessary << endl;  
        
    }
    
    /**
    for (int i = 0; i <= q.size()-1; i++) {
        
        cout << q[i] << ", ";
        
    }
    cout << endl;
    **/

}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
