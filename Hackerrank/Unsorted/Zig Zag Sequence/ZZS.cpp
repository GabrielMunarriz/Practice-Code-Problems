#include <bits/stdc++.h>
using namespace std;

void findZigZagSequence(vector < int > a, int n){
    sort(a.begin(), a.end());
    int mid = n/2; //Change 1: ((n+1)-1)/2 because we start counting at 0.
    swap(a[mid], a[n-1]);

    int st = mid + 1;
    int ed = n - 2; //Change 2: again, (n-1)-1. Extra -1 because indexes start at 0.
    while(st <= ed){
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1; //Change 3: We're supposed to decrease ed so that the loop stops. We're supposed to be swapping elements at either side of the righthand side from outer elements to inner.
    }
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main() {
    int n, x;
    int test_cases;
    cin >> test_cases;

    for(int cs = 1; cs <= test_cases; cs++){
        cin >> n;
        vector < int > a;
        for(int i = 0; i < n; i++){
            cin >> x;
            a.push_back(x);
        }
        findZigZagSequence(a, n);
    }
}



