/*The complete oriented weighted graph is given by the adjacency matrix. Construct a matrix of shortest paths between its vertices.
It is guaranteed that there are no negative weight cycles in the graph.*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;

void floyd(vector<vector<ll>>& graph) {
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
signed main() {
    cin >> n;

    vector<vector<ll>> graph;
    graph.resize(n);

    for (ll i = 0; i < n; ++i) {
        graph[i].resize(n);
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    floyd(graph);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
