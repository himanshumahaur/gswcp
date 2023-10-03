#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> item;
unordered_map<int, int> myhash;

int getcoin(vector<int>& coins, int amount) {
    if(myhash.count(amount)) return myhash[amount];

    if(amount==0) return 0;
    if(amount<0) return INT_MAX-1;
    int num = INT_MAX-1;
    for(int i=0; i<coins.size(); i++) {
        num = min(num, getcoin(coins, amount-coins[i]) + 1);
    }

    myhash[amount] = num;
    return num;
}

int main() {
    cin >> n >> t;
    item.resize(n);

    for(int i=0; i<n; i++) {
        cin >> item[i];
    }

    int coin = getcoin(item, t);

    if(coin==INT_MAX-1) cout << -1;
    else cout << coin;
    
    return 0;
}