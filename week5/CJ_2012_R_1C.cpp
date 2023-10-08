#include<bits/stdc++.h>
using namespace std;

bool dim(int u, vector<vector<int>>& e, unordered_map<int, int>& vis) {
    bool carbon = false;
    if(vis.count(u)) return true;

    for(auto i:e[u]) {
        carbon = dim(i, e, vis);
        if(carbon) break;
    }

    vis[u] = carbon;
    return carbon;
}

int main() {
    // taking input
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int v;
        cin >> v;

        vector<vector<int>> e(v+1);

        for(int j=1; j<v+1; j++) {
            
            int n;
            cin >> n;

            for(int k=0; k<n; k++) {
                int tmp;
                cin >> tmp;
                e[j].push_back(tmp);
            }

        }

        bool carbon = false;
        for(int j=1; j<v+1; j++) {
            unordered_map<int, int> vis;
            carbon = dim(j, e, vis);
            if(carbon) break;
        }

        if(carbon) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}