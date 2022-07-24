#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename type, typename cmp = less<type>>
//using pbds_set = tree<type, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
vector<vector<ll>>g;
ll log_2;
vector<ll>tin, tout;
ll timer;
vector<vector<ll>>up;
void dfs(ll v, ll p = 0){
    tin[v] = timer++;
    up[v][0] = p;
    for(ll i = 1; i<=log_2; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto to:g[v]){
        if(to != p)dfs(to, v);
    }
    tout[v] = timer++;
} 
bool is_ancestor(ll a, ll b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}
ll lca(ll a, ll b){
    if(is_ancestor(a, b))return a;
    if(is_ancestor(b, a))return b;
    for(ll i = log_2; i>=0; i--){
        if(!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    g.resize(n);
    for(ll i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    log_2 = 1;
    while((1<<n)<=n)log_2++;
    for(ll i = 0; i<n; i++)up[i].resize(log_2+1);
    dfs(0);
    ll a, b;
    cin>>a>>b;
    a--, b--;
    cout<<lca(a, b);
    return 0;
}
