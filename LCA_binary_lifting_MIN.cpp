
// хз работает оно или нет лол
// PS: ладно, оно работает



#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename type, typename cmp = less<type>>
//using pbds_set = tree<type, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
ll n, log_2;
const int MAXN = 200001;
vector<pair<ll, ll>>g[MAXN];
ll timer;
ll tin[MAXN], tout[MAXN];
pair<ll, ll>up[MAXN][20];
void dfs(ll v, ll p = 1, ll c = MAXN){
    tin[v] = timer++;
    up[v][0] = {p, c};
    for(ll i = 1; i<=log_2; i++){
        up[v][i].first = up[up[v][i-1].first][i-1].first;
        up[v][i].second = min(up[v][i-1].second, up[up[v][i-1].first][i-1].second);
    }
    for(auto to:g[v]){
        dfs(to.first, v, to.second);
    }
    tout[v] = timer++;
}
bool is_ancestor(ll a, ll b){
    return tin[a]<=tin[b] and tout[a]>=tout[b];
}
ll min_lca(ll a, ll b){
    ll res = INT_MAX;
    for(ll i = log_2; i>=0; i--){
        if(!is_ancestor(up[a][i].first, b)){
            res = min(res, up[a][i].second);
            a = up[a][i].first;
        }
    }
    if(!is_ancestor(a, b)){
        res = min(res, up[a][0].second);
    }
    for(ll i = log_2; i>=0; i--){
        if(!is_ancestor(up[b][i].first, a)){
            res = min(res, up[b][i].second);
            b = up[b][i].first;
        }
    }
    if(!is_ancestor(b, a)){
        res = min(res, up[b][0].second);
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m;
    cin>>n;
    log_2 = 1;
    while ((1 << log_2) <= n) ++log_2;
    for (int i = 2; i < n + 1; i++) {
        ll x;
        ll p;
        cin>>x>>p;
        g[x].push_back(make_pair(i, p));
    }
    dfs(1);

    cin>>m;
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin>>u>>v;
        ll res = min_lca(u, v);
        cout<<res<<"\n";
    }
    return 0;
}
