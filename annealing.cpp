#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
const ll K = 20;
const long long inf = 2e9;
const ll big_num = 2e18;
string abc = "abcdefghijklmnopqrstuvwxyz";
ll n;
mt19937 rnd(4321);
ll d[500][500];
ll f(vector<ll>&p){
  ll dist = 0;
  ll to = p.back();
  for(auto v:p){
    dist+=d[v][to];
    to = v;
  }
  return dist;
}
signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  ll m;
  cin>>m;
  for(ll i = 1; i<=n; i++){
    for(ll j = 1; j<=n; j++){
      d[i][j] = inf;
    }
  }
  for(ll i = 0; i<m; i++){
    ll u, v, w;
    cin>>u>>v>>w;
    d[u][v] = w;
    d[v][u] = w;
  }
  vector<ll>p(n);
  for(ll i = 1; i<=n; i++)p[i-1] = i;
  random_shuffle(p.begin(), p.end());
  ll ans = f(p);
  long double t = 1;
  for(ll q = 0; q<10000; q++){
    t*=0.99;
    vector<ll>cur_p = p;
    ll a = rnd()%n;
    ll b = rnd()%n;
    swap(cur_p[a], cur_p[b]);
    ll fy = f(cur_p);
    if(fy<ans || rnd()>exp((fy-ans)/t)){
      p = cur_p;
      ans = fy;
    }
    else{
      swap(cur_p[a], cur_p[b]);
    }
  }
  cout<<ans<<"\n";
  for(auto i:p){
    cout<<i<<" ";
  }
  cout<<"\n";
  return 0;
}
