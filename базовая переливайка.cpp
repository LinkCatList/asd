#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100001;
vector<vector<ll>>g;
ll color[MAXN], res[MAXN]; // res - количество вершин в поддереве i
set<ll>sett[MAXN];
void add(set<ll>&a, set<ll>&b){
    if(a.size()<b.size())a.swap(b);
	for(auto i:b)a.insert(i);
    b.clear();
}
void dfs(ll v, ll p){
    sett[v].insert(color[v]);
    for(auto t:g[v]){
        if(t == p)continue;
        dfs(t, v);
        add(sett[v], sett[t]);
    }
    res[v] = sett[v].size();
}
ll num = 1;
void count(ll v, ll p){
    color[v] = num++;
    for(auto to:g[v]){
        if(to != p){
            count(to, v);
        }
    }
}
vector<ll>comp; // компонента вершины i
map<ll, ll>vertex_cnt; // количество вершин в компоненте
ll cnt = 0;
vector<bool>used;
map<pair<ll, ll>, ll>ans; // говно какое-то
void count_comps(ll v){
      used[v] = true;
      comp[v] = cnt;
      vertex_cnt[cnt]++;
      for(auto to:g[v]){
            if(!used[to]){
                  comp[to] = cnt;
                  count_comps(to);
            }
      }
}
ll component; // количество вершин в текущей компоненте
void dfs_for_ans(ll v, ll p){
      used[v] = true;
      for(auto to:g[v]){
            if(used[to] or to == p)continue;
            dfs_for_ans(to, v);
            ans[{v, to}] = min(res[v], res[to])*(component-min(res[v], res[to]));
            ans[{to, v}] = min(res[v], res[to])*(component-min(res[v], res[to]));
      }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    g.resize(n);
    used.assign(n, 0);
    comp.resize(n);
    map<ll, pair<ll, ll>>mp;
    for(ll i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        mp[i+1] = {a, b};
    }
    for(ll i = 0; i<n; i++){
        if(!used[i]){
            count_comps(i);
            cnt++;
        }
    }
    //for(auto i:vertex_cnt)cout<<i.second<<" ";
    //for(ll i = 0; i<n; i++)cout<<res[i]<<" ";
    used.assign(n, 0);
    for(ll i = 0; i<n; i++){
      if(!used[i]){
            num = 1;
            count(i, i);
            dfs(i, i);
            component = vertex_cnt[comp[i]];
            dfs_for_ans(i, i);
      }
    }
    //for(ll i = 0; i<n; i++)cout<<color[i]<<" ";
    ll test;
    cin>>test;
    while(test--){
      ll a;
      cin>>a;
      cout<<ans[mp[a]]<<"\n";
    }
    return 0;
}
