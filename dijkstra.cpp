#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main() {
    long long n, from, to;
    cin >> n >> from >> to;
    from--;to--;
    vector < vector < pair<long long,long long>>> g (n);
    for (long long i=0; i<n; ++i)
        for (long long j=0; j<n; ++j){
            long long t;
            cin>>t;
            if (t!=-1 && i!=j)g[i].push_back(make_pair(j, t));
        }
    long long s = from; 

    vector<long long> d (n, INF),  p (n);
    d[s] = 0;
    vector<long long> u (n);
    for (long long i=0; i<n; ++i) {
        long long v = -1;
        for (long long j=0; j<n; ++j)
            if (!u[j] && (v == -1 or d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j=0; j<g[v].size(); ++j) {
            long long to = g[v][j].first,
                len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    if (d[to]!=INF)cout<<d[to];
    else cout<<-1;
}
