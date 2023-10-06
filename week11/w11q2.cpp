#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int mstop(int pos, vector<int>& vec) {
    if(memo.count(pos)) return memo[pos];
    int res = INT_MAX;

    if(pos==0) return 0;
    if(pos<0) return INT_MAX;
    
    for(int i=pos-1; i>=0; i--) {
        if(vec[i]+i>=pos) res = min(res, mstop(i, vec));
    }

    memo[pos] = res+1;
    return res + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);

    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << mstop(n-1, vec);

    return 0;
}