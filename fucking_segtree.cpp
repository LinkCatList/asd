#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template <typename type, typename cmp = less<type>>
//using pbds_set = tree<type, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
const ll K = 460;
const ll inf = 2e18;
const ll big_num = 2e18;
string abc = "abcdefghijklmnopqrstuvwxyz";
const ll LG = 31;
struct node{
  ll mx, mn, mx_id, mn_id;
};
ll sz;
vector<node>t;
void init(ll n){
  sz = 1;
  while(sz<n){
    sz*=2;
  }
  t.assign(2*sz-1, {0, 0, 0, 0});
}

void build(vector<ll>&a, ll x, ll lx, ll rx){
  if(rx-lx == 1){
    if(lx<(ll)a.size()){
      t[x] = {a[lx], a[lx], lx, lx};
    }
  }
  else{
    ll m = (lx+rx)/2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);

    if(t[2*x+1].mn<t[2*x+2].mn){
      t[x].mn = t[2*x+1].mn;
      t[x].mn_id = t[2*x+1].mn_id;
    }
    else if(t[2*x+1].mn == t[2*x+2].mn){
      t[x].mn = t[2*x+1].mn;
      t[x].mn_id = min(t[2*x+1].mn_id, t[2*x+2].mn_id);
    }
    else{
      t[x].mn = t[2*x+2].mn;
      t[x].mn_id = t[2*x+2].mn_id;
    }

    if(t[2*x+1].mx>t[2*x+2].mx){
      t[x].mx = t[2*x+1].mx;
      t[x].mx_id = t[2*x+1].mx_id;
    }
    else if(t[2*x+1].mx == t[2*x+2].mx){
      t[x].mx = t[2*x+1].mx;
      t[x].mx_id = min(t[2*x+1].mx_id, t[2*x+2].mx_id);
    }
    else{
      t[x].mx = t[2*x+2].mx;
      t[x].mx_id = t[2*x+2].mx_id;
    }
  }
}

void build(vector<ll>&a){
  init((ll)a.size());
  build(a, 0, 0, sz);
}

void upd(ll i, ll v, ll x, ll lx, ll rx){
  if(rx-lx == 1){
    t[x] = {v, v, i, i};
  }
  else{
    ll m = (lx+rx)/2;
    if(i<m) upd(i, v, 2*x+1, lx, m);
    else upd(i, v, 2*x+2, m, rx);

    if(t[2*x+1].mn<t[2*x+2].mn){
      t[x].mn = t[2*x+1].mn;
      t[x].mn_id = t[2*x+1].mn_id;
    }
    else if(t[2*x+1].mn == t[2*x+2].mn){
      t[x].mn = t[2*x+1].mn;
      t[x].mn_id = min(t[2*x+1].mn_id, t[2*x+2].mn_id);
    }
    else{
      t[x].mn = t[2*x+2].mn;
      t[x].mn_id = t[2*x+2].mn_id;
    }

    if(t[2*x+1].mx>t[2*x+2].mx){
      t[x].mx = t[2*x+1].mx;
      t[x].mx_id = t[2*x+1].mx_id;
    }
    else if(t[2*x+1].mx == t[2*x+2].mx){
      t[x].mx = t[2*x+1].mx; 
      t[x].mx_id = min(t[2*x+1].mx_id, t[2*x+2].mx_id);
    }
    else{
      t[x].mx = t[2*x+2].mx;
      t[x].mx_id = t[2*x+2].mx_id;
    }
  }
}
void upd(ll i, ll v){
  return upd(i, v, 0, 0, sz);
}
pair<ll, ll> get_min(ll l, ll r, ll x, ll lx, ll rx){
  if(l>=rx || lx>=r){
    return {inf, -1};
  }
  if(lx>=l && rx<=r){
    return {t[x].mn, t[x].mn_id};
  }
  ll m = (lx+rx)/2;

  auto s1 = get_min(l, r, 2*x+1, lx, m);
  auto s2 = get_min(l, r, 2*x+2, m, rx);

  if(s1.first<s2.first){
    return s1;
  }
  else if(s1.first == s2.first){
    if(s1.second<s2.second)return s1;
    else return s2;
  }
  else{
    return s2;
  }
}
ll get_min(ll l, ll r){
  auto ans = get_min(l, r, 0, 0, sz);
  return ans.second;
}

pair<ll, ll> get_max(ll l, ll r, ll x, ll lx, ll rx){
  if(l>=rx || lx>=r){
    return {-inf, -1};
  }
  if(lx>=l && rx<=r){
    return {t[x].mx, t[x].mx_id};
  }
  ll m = (lx+rx)/2;

  auto s1 = get_max(l, r, 2*x+1, lx, m);
  auto s2 = get_max(l, r, 2*x+2, m, rx);

  if(s1.first>s2.first){
    return s1;
  }
  else if(s1.first == s2.first){
    if(s1.second<s2.second)return s1;
    else return s2;
  }
  else{
    return s2;
  }
}
ll get_max(ll l, ll r){
  auto ans = get_max(l, r, 0, 0, sz);
  return ans.second;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin>>n;
  ll m;
  cin>>m;

  vector<ll>cnt(n, 0);
  vector<set<ll>>disable(n);
  vector<ll>a(n, 0);

  build(a);

  ll q;
  cin>>q;
  while(q --> 0){
    string s;
    cin>>s;
    if(s == "RESET"){
      ll i;
      cin>>i;
      i--;
      cnt[i]++;
      disable[i].clear();
      upd(i, cnt[i]*(m-(ll)disable[i].size()));
    }
    if(s == "DISABLE"){
      ll i, j;
      cin>>i>>j;
      i--;
      disable[i].insert(j);
      upd(i, cnt[i]*(m-(ll)disable[i].size()));
    }
    if(s == "GETMAX"){
      cout<<get_max(0, n)+1<<"\n";
    }
    if(s == "GETMIN"){
      cout<<get_min(0, n)+1<<"\n";
    }
  }
  return 0;
}
