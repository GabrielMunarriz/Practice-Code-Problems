// C++ Program to implement
// Split String By Space Into Vector
// Using getline() method
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    // String variable i.e, string to be split
    string str = "Geeks for Geeks";
 
    // variable to store token obtained from the original
    // string
    string s;
 
    // constructing stream from the string
    stringstream ss(str);
 
    // declaring vector to store the string after split
    vector<string> v;
 
    // using while loop until the getline condition is
    // satisfied
    // ' ' represent split the string whenever a space is
    // found in the original string
    while (getline(ss, s, ' ')) {
 
        // store token string in the vector
        v.push_back(s);
    }
 
    // print the vector
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
 
    return 0;
}