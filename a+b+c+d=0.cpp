#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b){
  return a.second.second<b.second.second;
}
bool bin_search(vector<pair<ll, pair<ll, ll>>>a, ll x){
  ll l = -1, r = a.size();
  while(r-l>1){
    ll m = (r+l)/2;
    if(a[m].second.second>x)r = m;
    else l = m;
  }
  if(a[l].second.second == x)return true;
  else return false;
}
ll low_bound(vector<pair<ll, pair<ll, ll>>>a, ll x){
  ll l = -1, r = a.size();
  while(r-l>1){
    ll m = (r+l)/2;
    if(a[m].second.second>x)r = m;
    else l = m;
  }
  return l;
}
signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin>>n;
  vector<ll>v(n);
  for(ll i = 0; i<n; i++)cin>>v[i];
  vector<pair<ll, pair<ll, ll>>>cnt;
  for(ll i = 0; i<n; i++){
    for(ll j = 0; j<n; j++){
      cnt.push_back({v[i], {v[j], v[i]+v[j]}});
    }
  }
  sort(cnt.begin(), cnt.end(), cmp);
  for(ll i = 0; i<n; i++){
    for(ll j = 0; j<n; j++){
      ll sum = -(v[i]+v[j]);
      if(bin_search(cnt, sum)){
        ll indx = low_bound(cnt, sum);
        cout<<(cnt[indx].first)<<" "<<(cnt[indx].second.first)<<" "<<v[i]<<" "<<v[j];
        return 0;
      }
    }
  }
  return 0;
}
