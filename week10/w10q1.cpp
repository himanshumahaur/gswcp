#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> item;
unordered_map<int, int> myhash;

int least(int t) {
    int res = INT_MAX-1;

    if(t==0) return 0;

    for(int i=0; i<n; i++) {
        if(t-item[i]<0) break;

        int prev;
        if(myhash.count(t-item[i])) prev = myhash[t-item[i]];
        else prev = least(t-item[i]);

        res = min(res, prev);
    }

    myhash[t] = res+1;
    return res+1;
}

int main() {
    cin >> n >> t;

    item.resize(n);

    for(int i=0; i<n; i++) {
        cin >> item[i];
    }

    int ans = least(t);

    if(ans == 2147483647) cout << -1;
    else cout << ans;
}