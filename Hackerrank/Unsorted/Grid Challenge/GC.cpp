#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
    
    bool isAlphabetical = true;
    string output;
    
    //first, we sort each row.
    for (int i = 0; i <= grid.size()-1; i++) {
        
        sort(grid[i].begin(), grid[i].end());
        
    }

    //I read the instructions wrong. I thought we had to check if both horizontal and vertical letters are in alphabetical order. Turns out I had to sort horizontal first THEN do a vertical test. I'm saving the code anyway.
    /**
    //horizontal test
    for (int i = 0; i <= grid.size() - 1; i++) {
        
        for (int j = 1; j <= grid[i].size() - 1; j++) {
            
            //Consider abc. we check if b < a, then c < b.
            if (grid[i][j] < grid[i][j-1]) {
                
                cout << "i = " << i << endl;
                cout << "j = " << j << endl;
                cout << "not alphabetical - horizontal!" << endl;
                
                isAlphabetical = false;
                break;
                
            }
            
        }
        
        //Alphabetical Check. If it already fails, we don't need to do the other rows.
        if (isAlphabetical == false) {
            
            break;
            
        }        
        
    }
    
    
    //Alphabetical Check. If isAlphabetical is still true, we do vertical test.
    if (isAlphabetical == true) {
            
        //vertical test (wrong btw. refer to updated version)
        for (int i = 1; i <= grid.size() - 1; i++) {
            
            int j = 0;
            
            //Consider abc. we check if b < a, then c < b.
            if (grid[i][j] < grid[i-1][j]) {
                
                cout << "i = " << i << endl;
                cout << "j = " << j << endl;
                cout << "not alphabetical - vertical!" << endl;
                    
                isAlphabetical = false;
                break;
                    
            }
            
            j++;      
            
        }
            
    }  
    **/
    
    //updated vertical test
    for (int i = 1; i <= grid.size() - 1; i++) {
            
        for (int j = 0; j <= grid[i].size() - 1; j++) {
            
            //Consider abc. we check if b < a, then c < b.
            if (grid[i][j] < grid[i-1][j]) {
                
                cout << "i = " << i << endl;
                cout << "j = " << j << endl;
                cout << "not alphabetical - vertical!" << endl;
                    
                isAlphabetical = false;
                break;
                    
            } 
            
        }
       
    }
    
    
    if (isAlphabetical == true) {
        
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
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

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
