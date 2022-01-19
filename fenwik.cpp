#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6;
ll f[MAXN];
ll a[MAXN];
void upd(ll x, ll add) {
    for (ll i = x; i < MAXN; i += i & -i) {
        f[i] += add;
    }
}

ll get(ll x) {
    int res = 0;
    for (ll i = x; i > 0; i -= i & -i) {
         res += f[i];
    }
    return res;
}
signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin>>n>>k;
  char c;
  ll l, r;
  for(ll i = 0; i<k; i++){
      cin>>c>>l>>r;
      if(c == 'A'){
        upd(l, r-a[l]);
        a[l] = r;
      }
      else{
        cout<<get(r) - get(l-1)<<"\n";
      }
  }
  return 0;
}
