#include<bits/stdc++.h>
using namespace std;

// output
// 4
// 3

void print(vector<int> vec) {
    for(auto i:vec) {
        cout << i << " ";
    }
    cout << endl;
}

int msp(vector<int> vec) {
    int n = vec.size();
    vector<int> res(n, 0);

    for(int i=0; i<n; i++) {
        if(i>0) res[i] = max(res[i], res[i-1]);
        for(int j=0; j<i; j++) {
            if(vec[i]==vec[j]) res[i] = max(res[i], (i-j+1)+res[j-1]);
        }
    }
    
    return res[n-1];
}

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int n;
        cin >> n;

        vector<int> vec(n);
        for(int j=0; j<n; j++) {
            cin >> vec[j];
        }

        cout << msp(vec) << endl;
    }

    return 0;
}