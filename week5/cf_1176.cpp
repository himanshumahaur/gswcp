#include<bits/stdc++.h>
using namespace std;

int main() {
    // taking input
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> e(n+1);

        for(int j=0; j<m; j++) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        queue<int> q;
        q.push(1);

        vector<int> dis(n+1, -2);
        dis[1] = 0;

        int layer = -1;

        vector<int> veca;
        vector<int> vecb;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(layer!=dis[u]) layer = dis[u];

            if(layer%2) veca.push_back(u);
            else vecb.push_back(u);

            for(auto i:e[u]) {
                if(dis[i]<0) {
                    dis[i] = dis[u] + 1;
                    q.push(i);
                }
            }
        }

        if(veca.size()<vecb.size()) {
            cout << veca.size() << endl;
            for(auto i:veca) cout << i << " ";
        }
        else {
            cout << vecb.size() << endl;
            for(auto i:vecb) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}