#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld a;
ld M_PI = 3.14;
const int eps = 0.000001;
bool check(ld x){
    if(cos(x)>=a*x) return 1;
    else return 0;
}
signed main() {
    cin>>a;

    ld l = 0, r = M_PI;
    for(int i = 0; i<100; i++){
        ld m = (r+l)/2;
        if(check(m)){
            l = m;
        }
        else{
            r = m;
        }
    }
    cout<<setprecision(10)<<l;
    return 0;
}
