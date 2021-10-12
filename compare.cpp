#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define PB push_back
#define PoB pop_back

ll n;

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    ll s1 = 0; ll s2 = 0;
    s1 = abs(a.first % 10);
    s2 = abs(b.first % 10);
    if (s1 == s2) {
        return a.second < b.second;
    }
    else {
        return s1 < s2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<pair<ll, ll>>arr(n);
    for (ll i = 0; i < arr.size(); i++) cin >> arr[i].first;
    for (ll i = 0; i < arr.size(); i++) arr[i].second = i;
    sort(arr.begin(), arr.end(), compare);
    for (ll i = 0; i < arr.size(); i++) {
        cout << arr[i].first << " ";
    }

}
