#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll m;
const int sz = 1e5+5;
ll h1[sz], p1[sz];
ll h2[sz], p2[sz];
const long long mod = 1e9+7;
ll get1(ll l, ll r){
    return h1[r+1]-h1[l]*p1[r-l+1];
}
ll get2(ll l, ll r){
    return h2[r+1]-h2[l]*p2[r-l+1];
}
ll find(string t, ll start){
    ll l = 0, r = t.size();
    while(r-l>1){
        ll m = (r+l)/2;
        if(get2(0, m) == get1(start, start+m)){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l+start;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>t>>s;
    /*h1[0] = 0;
    p1[0] = 1;
    for(ll i = 0; i<s.size(); i++){
        h1[i+1] = h1[i]*mod+s[i];
        p1[i+1] = p1[i]*mod;
    }
    h2[0] = 0;
    p2[0] = 1;
    for(ll i = 0; i<t.size(); i++){
        h2[i+1] = h2[i]*mod+t[i];
        p2[i+1] = p2[i]*mod;
    }*/
    for(ll i = 0; i<s.size(); i++){
        ll indx = find(t, i);
        if(get1())
    }
    return 0;
}
