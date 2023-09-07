#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> seen;
    int n, m;

    cin >> n >> m;

    map<int, set<int>> graph;
    vector<int> inserted(n+1, 0);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    int count = 1;

    seen.insert(1);
    inserted[1] = 1;
    while(!seen.empty()) {
        int p = *seen.begin();
        cout << p << " ";

        seen.erase(seen.begin());

        for(auto i:graph[p]) {
            if(!inserted[i]) seen.insert(i);
            inserted[i] = 1;
        }
    }

    return 0;
}