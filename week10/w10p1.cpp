#include<bits/stdc++.h>
using namespace std;

int mod(int x) {
    if(x>0) return x;
    else return -1*x;
}

int getval(vector<int>& vec, int idx) {
    if(idx==0) return 0;
    int a = INT_MAX, b = INT_MAX;
    if(idx-1>=0) a = getval(vec, idx-1) + mod(vec[idx]-vec[idx-1]);
    if(idx-2>=0) b = getval(vec, idx-2) + mod(vec[idx]-vec[idx-2]);
    return min(a, b);
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << getval(vec, n-1);
    return 0;
}