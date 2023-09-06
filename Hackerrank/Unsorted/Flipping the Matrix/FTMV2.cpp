#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int flippingMatrix(vector<vector<int>> matrix) {
    
    long maximalSum = 0;
    vector<long> currentCandidates;

    //how do we find the top left quadrant?
    //the top left quadrant starts from:  
    //row matrix[0] to row matrix[n-1]
    //column matrix[0][0] to column matrix[0][n-1]
    
    //first we gotta find the max of the top left corner of the top left quadrant. 
    //The possible numbers are the corners of the entire matrix.
    
    for (int i = 0; i <= (matrix.size()/2)-1; i++) {
        
        for (int j = 0; j <= (matrix.size()/2)-1; j++) {
            
            currentCandidates.clear();
            
            if (i == 0) {
                
                // looking for max of outer corners
                if (j == 0) { // AKA if j == i
                
                    //add all outer corners into a vector
                    currentCandidates.push_back(matrix[0][0]);
                    currentCandidates.push_back(matrix[0][matrix.size()-1]);
                    currentCandidates.push_back(matrix[matrix.size()-1][0]);
                    currentCandidates.push_back(matrix[matrix.size()-1][matrix.size()-1]);
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());

                    //add maximum of vector to maximal sum
                    cout << "a max number: " << currentCandidates[currentCandidates.size()-1] << endl;
                    maximalSum += currentCandidates[currentCandidates.size()-1];
                    cout << "at maximal sum i = 0 && j = 0 : " << maximalSum << endl;
                
                //looking for max of matrix[0][1] to matrix [0][size-2] and 
                //matrix[size-1][1] to matrix [size-1][size-2]
                } else if (j == 1) { // AKA if j == i + 1
                    
                    //add all of the elements to a vector
                    for (int k = 1; k <= matrix[0].size()-2; k++) {
                        
                        currentCandidates.push_back(matrix[0][k]);
                        currentCandidates.push_back(matrix[matrix.size()-1][k]);
                        
                    }
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());
                    
                    //add the highest n-1 items to maximal sum.
                    for (int k = 0; k <= (matrix.size()/2)-2; k++) {
                        
                        cout << "a max number: " << currentCandidates[(currentCandidates.size()-1)-k] << endl;
                        maximalSum += currentCandidates[(currentCandidates.size()-1)-k];
                        
                    }
                    
                    cout << "at maximal sum i = 0 && j = " << j << ": " << maximalSum << endl;
                    
                } 
                
            } else if (i == (matrix.size()/2)-1) {
                
                if (j == i) {
                    
                    //add all outer corners into a vector
                    currentCandidates.push_back(matrix[i][j]);
                    currentCandidates.push_back(matrix[i][j+1]);
                    currentCandidates.push_back(matrix[i+1][j]);
                    currentCandidates.push_back(matrix[i+1][j+1]);
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());
                    
                    //add maximum of vector to maximal sum
                    cout << "a max number: " << currentCandidates[currentCandidates.size()-1] << endl;
                    maximalSum += currentCandidates[currentCandidates.size()-1];
                    cout << "at maximal sum i = " << i << " && j = " << j << ": " << maximalSum << endl;
                    
                
                } else if (j == i - 1) {
                    
                    //add all of the elements to a vector
                    for (int k = i; k <= i + 1; k++) {
                        
                        currentCandidates.push_back(matrix[k][j]);
                        currentCandidates.push_back(matrix[k][matrix.size()-1-j]);
                        
                    }
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());
                    
                    //add maximum of vector to maximal sum
                    cout << "a max number: " << currentCandidates[currentCandidates.size()-1] << endl;
                    maximalSum += currentCandidates[currentCandidates.size()-1];
                    cout << "at maximal sum i = " << i << " && j = " << j << ": " << maximalSum << endl;
                    
                }                       
                
            } else {
                
                if (j == i) {
                    
                    //add all "inner corners" into a vector
                    currentCandidates.push_back(matrix[i][j]);
                    currentCandidates.push_back(matrix[i][matrix.size()-1-j]);
                    currentCandidates.push_back(matrix[matrix.size()-1-i][j]);
                    currentCandidates.push_back(matrix[matrix.size()-1-i][matrix.size()-1-j]);
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());
                    
                    //add maximum of vector to maximal sum
                    cout << "a max number: " << currentCandidates[currentCandidates.size()-1] << endl;
                    maximalSum += currentCandidates[currentCandidates.size()-1];
                    cout << "at maximal sum i = " << i << " && j = " << j << ": " << maximalSum << endl;
                    
                } else if (j == i - 1) {
                    
                    //add all of the elements to a vector
                    for (int k = i; k <= matrix.size()-1-i; k++) {
                        
                        currentCandidates.push_back(matrix[k][j]);
                        currentCandidates.push_back(matrix[k][matrix.size()-1-j]);
                        
                    }
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());
                    
                    //add the highest n-1 items to maximal sum.
                    for (int k = 0; k <= (matrix.size()/2)-1-i; k++) {
                        
                        cout << "a max number: " << currentCandidates[(currentCandidates.size()-1)-k] << endl;
                        maximalSum += currentCandidates[(currentCandidates.size()-1)-k];
                        
                    }
                    
                    cout << "at maximal sum i = " << i << " && j = " << j << ": " << maximalSum << endl;
                    
                } else if (j == i + 1) {
                    
                    //add all of the elements to a vector
                    for (int k = j; k <= matrix[i].size()-1-j; k++) {
                        
                        currentCandidates.push_back(matrix[i][k]);
                        currentCandidates.push_back(matrix[matrix.size()-1-i][k]);
                        
                    }
                    
                    //sort vector
                    sort(currentCandidates.begin(), currentCandidates.end());
                    
                    //add the highest n-2 items to maximal sum.
                    for (int k = 0; k <= (matrix.size()/2)-1-j; k++) {
                        
                        cout << "a max number: " << currentCandidates[(currentCandidates.size()-1)-k] << endl;
                        maximalSum += currentCandidates[(currentCandidates.size()-1)-k];
                        
                    }
                    
                    cout << "at maximal sum i = " << i << " && j = " << j << ": " << maximalSum << endl;
                    
                }
                
            } 
            
            
            
            
        }
        
        //cout << "maximal sum: " << maximalSum << endl;
        
    }
    
    return maximalSum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

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
