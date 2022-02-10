#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>perm;
ll cnt[20];
//maxelem - in permutation
void generatePermitations(ll n, ll maxelem){
    if(n == 0){
        for(auto i:perm) cout<<i<<" ";
        cout<<"\n";
    }
    else{
        for(ll curelem = 1; curelem<=maxelem; curelem++){
            if(cnt[curelem] == 0){
                perm.push_back(curelem);
                cnt[curelem] = 1;
                generatePermitations(n-1, maxelem);
                cnt[curelem] = 0;
                perm.pop_back();
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    generatePermitations(n, n);
    return 0;
}
