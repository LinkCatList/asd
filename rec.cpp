#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x){ // числа фибоначчи
    if(x == 0 or x == 1)return 1;
    return f(x-1)+f(x-2);
}
//------------------------------------------------
const int MAXN = 1000;
ll mem[MAXN];
ll f_mem(ll x){ // фибоначчи с мемоизацией
    if(mem[x] != -1)return mem[x];
    return mem[x] = f_mem(x-1)+f_mem(x-2);
}
//signed main(){
//    for(ll i = 0; i<MAXN; i++)mem[i] = -1;
//    mem[0] = mem[1] = 1;
//    cout<<f_mem(10);
//}

//------------------------------------------------
void rev(ll n){ // реверс последовательности
    if(!n)return;
    ll x;
    cin>>x;
    rev(n-1);
    cout<<x<<" ";
}
//------------------------------------------------
void hb(ll a, ll b, ll c, ll n){ // ханойские башни
    if(n == 1){
        cout<<a<<" "<<c<<"\n";
        return;
    }
    hb(a, c, b, n-1);
    cout<<a<<" "<<c<<"\n";
    hb(b, a, c, n-1);
}
//signed main(){
//  hb(0, 1, 2, 3);
//}

//------------------------------------------------

