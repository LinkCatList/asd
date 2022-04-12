#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100*1000+17;
vector<ll>g[N], gr[N];
vector<vector<ll>> comps;
ll n, m, last, maxColor = 0;
ll tin[N], tup[N], colors[N], mult[N];
ll timer = 0;
set<ll>bridges;
bool used[N], used2[N];
map<pair<ll, ll>, ll>num;
pair<ll, ll>kek(ll a, ll b){
    if(a>b)swap(a, b);
    return {a, b};
}
void find(int v) {
    used2[v] = true;
    comps.back().push_back(v);

    for (int u: g[v]) {
        if (!used2[u]) {
            find(u);
        }
    }
}
void dfs(ll v, ll p = -1){

    used[v] = true;
    tin[v] = timer++;
    tup[v] = tin[v];

    for(auto to:g[v]){
        if(to == p)continue;

        if(used[to] == true){
            tup[v] = min(tup[v], tin[to]);
        }

        else{
            dfs(to, v);
            tup[v] = min(tup[v], tup[to]);
            if(tup[to]>tin[v] and !mult[num[kek(to, v)]]){
                bridges.insert(num[kek(to, v)]);
            }
        }
    }
}
void paint(ll v, ll color){
    colors[v] = color;
    for(auto to: g[v]){
        if(colors[to] == 0){
            if(bridges.find(num[kek(v, to)]) != bridges.end()){
                maxColor++;
                paint(to, maxColor);
            }
            else{
                paint(to, color);
            }
        }
    }
}
void solve(){
    timer = 1;
    for(ll i = 1; i<=n; i++){
        colors[i] = 0;
        if(!used[i])dfs(i);
    }
    maxColor = 0;
    for(ll i = 1; i<=n; i++){
        if(colors[i] == 0){
            maxColor++;
            paint(i, maxColor);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i = 1; i<=m; i++){
        ll x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        if(num[kek(x, y)] == 0){
            num[kek(x, y)] = i;
        }
        else{
            mult[num[kek(x, y)]] = true;
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (!used2[i]) {
            comps.push_back(vector<ll>());
            find(i);
        }
    }
    vector<pair<ll, ll>>ans;
    ll cnt = 0;
    for(vector<ll>&comp:comps){
        cnt++;
        for(auto v:comp){
            ans.push_back({v, cnt});
        }
    }
    solve();
//     for(ll i = 0; i<n; i++){
//         cout<<"comp: "<<ans[i].second<<" color: "<<colors[i+1]<<"\n";
//     }
    return 0;
}
/*
9 10
1 2
2 3
3 1
2 4
5 9
9 6
5 6
6 7
6 8
7 8
*/
