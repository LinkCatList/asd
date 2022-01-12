#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll getRand(){
    return rand()*32768+rand();
}
struct Node{
    ll x;
    ll y;
    ll sz;
    Node *l, *r;
    Node(ll _x){
        x = _x;
        y = getRand();
        sz = 1;
        l = r = nullptr;
    }
};
ll get_sz(Node *t);
void update(Node *t);
Node* merge(Node *t1, Node *t2){
    if (t1 == nullptr) { return t2; }
    if (t2 == nullptr) { return t1; }
    if (t1->y > t2->y){
        t1->r = merge(t1->r, t2);
        update(t1);
        return t1;
    }
    else{
        t2->l = merge(t1, t2->l);
        update(t2);
        return t2;
    }
}
void split(Node *t, ll x, Node *&t1, Node *&t2){
    if (t == nullptr){
        t1 = t2 = nullptr;
        return;
    }
    if (t->x < x){
        split(t->r, x, t->r, t2);
        t1 = t;
    }
    else{
        split(t->l, x, t1, t->l);
        t2 = t;
    }
    update(t);
}

ll get_sz(Node *t){
    if (t == nullptr) { return 0; }
    return t->sz;
}
void update(Node *t){
    if (t != nullptr){
        t->sz = 1 + get_sz(t->l) + get_sz(t->r);
    }
}
void add(Node *&t, ll x){
    Node *t1, *t2;
    split(t, x, t1, t2);
    Node* new_tree = new Node(x);
    t = merge(merge(t1, new_tree), t2);
}

void remove(Node *&t, ll x){
    Node *t1, *t2, *t3, *t4;
    split(t, x, t1, t2);
    split(t2, x + 1, t3, t4);
    t = merge(t1, t4);
    delete t3;
}
void print(Node *t){
    if (t != nullptr){
        print(t->l);
        cout << t->x << " ";
        print(t->r);
    }
}

int get_k(Node *t, ll k){
    if (k < get_sz(t->l)){
        return get_k(t->l, k);
    }
    else if (k == get_sz(t->l)){
        return t->x;
    }
    else{
        return get_k(t->r, k - get_sz(t->l) - 1);
    }
}
signed main() {
    Node *treap = nullptr;
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++)cin>>v[i];
    for(const auto &e : v){
        add(treap, e);
    }
    print(treap);
    cout << "\n";
    for(ll i = 0; i < v.size(); ++i){
        cout << get_k(treap, i) << " ";
    }
    cout << "\n";
    remove(treap, 5);
    print(treap);
    cout<<"\n";
    while(treap != nullptr){
        remove(treap, get_k(treap, 0));
        print(treap);
        cout << "\n";
    }
    return 0;
}
