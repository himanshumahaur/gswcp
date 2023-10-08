// Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.

// A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into 2 sets in such a way, that for each edge (u, v) that belongs to the graph, u and v belong to different sets. You can find more formal definitions of a tree and a bipartite graph in the notes section below.

// Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges they can add?

// A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. A cycle and a loop aren't the same .
// Input

// The first line of input contains an integer n — the number of nodes in the tree (1 ≤ n ≤ 105).

// The next n - 1 lines contain integers u and v (1 ≤ u, v ≤ n, u ≠ v) — the description of the edges of the tree.

// It's guaranteed that the given graph is a tree.
// Output

// Output one integer — the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.

#include<bits/stdc++.h>
using namespace std;

int main() {
    // taking input
    int n;
    cin >> n;

    vector<vector<int>> e(n+1);

    for(int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    // runnig bfs
    queue<int> q;
    q.push(1);

    vector<int> dis(n+1, -2);
    dis[1] = 0;

    long long a = 0;
    int layer = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(layer!=dis[u]) layer = dis[u];
        if(layer%2) a++;

        for(auto i:e[u]) {
            if(dis[i]<0) {
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }

    long long b = n-a;

    cout << (a*b)-(n-1);

    return 0;
}