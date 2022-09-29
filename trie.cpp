#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 3*100000+1;
string abc = "abcdefghijklmnopqrstuvwxyz";
struct node{
    node *next[27];
    ll cnt_terminal_vertex;
    node(){
        for(ll i = 0; i<26; i++){
            next[i] = nullptr;
        }
        cnt_terminal_vertex = 0;
    }
};
node *root = new node();
void add(string s){
    node *cur_v = root;
    for(ll i = 0; i<s.size(); i++){
        char c = s[i];
        if(cur_v->next[c-'a'] == nullptr){
            cur_v->next[c-'a'] = new node();
        }
        cur_v->cnt_terminal_vertex++;
        cur_v = cur_v->next[c-'a'];
    }
    cur_v->cnt_terminal_vertex++;
}
void ans(ll k, node *cur_v = root){
    for(ll i = 0; i<26; i++){
        if(cur_v->next[i] != nullptr and cur_v->next[i]->cnt_terminal_vertex>=k){
            cout<<(abc[i]);
            ans(k, cur_v->next[i]);
        }
        else if(cur_v->next[i] != nullptr){
            k-=(cur_v->next[i]->cnt_terminal_vertex);
        }
    }
}
signed main(){
    ll q;
    cin>>q;
    while(q--){
        ll c;
        cin>>c;
        if(c == 1){
            string s;
            cin>>s;
            add(s);
        }
        else{
            ll k;
            cin>>k;
            ans(k);
            cout<<"\n";
        }
    }
}
