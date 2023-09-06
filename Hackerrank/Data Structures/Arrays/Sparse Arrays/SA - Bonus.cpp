/**

I made this code because I misunderstood the problem, but it works.

Basically, this code counts the number of times the strings in queries occur in the strings in 
stringList.

However, if a string in query is a substring of a string in stringList, then it will count as well.

Apparently, the problem only asked that you searched if a string in query is exactly th same as a
string in stringList.

**/



#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    
    vector<int> queriesFrequency;
    for (int i = 0; i <= queries.size()-1; i++) {
        
        queriesFrequency.push_back(0);
        
    }
    

    for (int i = 0; i <= stringList.size() - 1; i++) {
        
        size_t found;
        
        for (int j = 0; j <= queries.size() - 1; j++) {
            
            found = stringList[i].find(queries[j]);
            
            if (found != string::npos) {
                
                cout << "match found! " << "i " << i << " j " << j << endl;
                cout << queries[j] << " in " << stringList[i] << endl;
                queriesFrequency[j]++;
                
            }
            
            //cout << "hi" << endl;
            
        }
        
        cout << endl;
        
    }
    
    return queriesFrequency;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stringList_count_temp;
    getline(cin, stringList_count_temp);

    int stringList_count = stoi(ltrim(rtrim(stringList_count_temp)));

    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++) {
        string stringList_item;
        getline(cin, stringList_item);

        stringList[i] = stringList_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(stringList, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
