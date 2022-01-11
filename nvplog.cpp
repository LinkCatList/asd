#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = -1e9;
const int inf2 = 1e9;
signed main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i = 0; i<n; i++)cin>>a[i];
    vector<ll>d(n);
    d[0] = -1e9;
    for(ll i = 1; i<n; i++)d[i] = inf2;
    vector<ll>pos(n);
    vector<ll>prev(n);

    ll len = 0;
    pos[0] = -1;
    for(ll i = 0; i<n; i++){
        ll j = upper_bound(d.begin(), d.end(), a[i])-d.begin();
        if(d[j-1]<a[i] and a[i]<d[j]){
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j-1];
            len = max(len, j);
        }
    }
    vector<ll>ans;
    ll p = pos[len];
    while(p!=-1){
        ans.push_back(p+1);
        p = prev[p];
    }
    reverse(ans.begin(), ans.end());
    for(auto i:ans)cout<<i<<" ";
}
