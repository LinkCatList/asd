#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int inf = 1e9;
ll upd;
ll n, m;
vector<vector<ll>>g;
vector<bool>used;
vector<ll>mt;
vector<vector<ll>>invers_g;
void print_graph(vector<vector<ll>>g){
    for(ll i = 0; i<n+upd-1; i++){
        cout<<i<<": ";
        for(auto to:g[i]){
            cout<<to<<" ";
        }
        cout<<"\n";
    }
}
vector<vector<ll>>g2;
vector<vector<ll>>make_invert_graph(vector<vector<ll>>g1, ll n){
    g2.resize(n+upd);
    for(ll i = 0; i<n+upd-1; i++)g2[i].clear();
    for(ll i = 0; i<n+upd-1; i++){
        ll ok = upd;
        //cout<<i<<": ";
        for(auto to:g1[i]){
            while(to != ok and ok<n+upd-1){
                if(ok >= upd and i>=upd){
                    ok++;
                    continue;
                }
                g2[i].push_back(ok);
                g2[ok].push_back(i);
                ok++;
            }
            ok++;
        }
    }
    return g2;
}
bool kun(ll v){
    if(used[v])return false;
    used[v] = true;
    for(ll i = 0; i<invers_g[v].size(); i++){
        ll to = invers_g[v][i];
        if(mt[to] == -1 or kun(mt[to])){
            mt[to] = v;
            return true;
        }
    }
    return false;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    upd = max(n, m);
    g.resize(n+upd);
    mt.assign(n+upd, -1);
    used.resize(n+upd);
    for(ll i = 0; i<n; i++){
        ll x = 1;
        while(true){
            cin>>x;
            if(x == 0)break;
            x--;
            g[i].push_back(x+upd);
            g[x+upd].push_back(i);
        }
    }
    invers_g = make_invert_graph(g, n);
    print_graph(invers_g);
    for(ll i = n; i<n+upd-1; i++){
        used.assign(n+upd, 0);
        kun(i);
    }
    for(ll i = 0; i<m; i++){
        if(mt[i] != -1){
            cout<<mt[i]<<" "<<i<<"\n";
        }
    }
    return 0;
}
