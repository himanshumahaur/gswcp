#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> s;

    vector<int> time(n, 0);
    map<int, vector<pair<int, int>>> graph;
    
    for(int i=0; i<n; i++) {
        cin >> m;
        for(int j=0; j<m; j++) {
            int a, b;
            cin >> a >> b;
            graph[j].push_back({a, b});
            graph[a].push_back({j, b});
        }
    }

    for(auto i:graph) {
        cout << i.first << ": ";
        for(auto j:i.second) {
            cout << j.first << " ";
        }
        cout << endl;
    }

    return 0;
}