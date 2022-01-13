#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = INT64_MAX;

struct Node {
    ll x, y, sz;
    Node* left, * right;

    Node(ll nx, ll ny) {
        x = nx; y = ny; sz = 1;
        left = right = NULL;
    }

};

ll get_sz(Node *T) {
    if (T) return T->sz;
    return 0;
}

void recount(Node * &T) {
    if (!T) return;
    T->sz = 1 + get_sz(T->left) + get_sz(T->right);
}

    Node* merge(Node * L, Node * R) {
    if (!L) return R;
    if (!R) return L;
    if (L->y < R->y) {
        L->right = merge(L->right, R);
        recount(L);
        return L;
    }
    else{
        R->left = merge(L, R->left);
        recount(R);
        return R;
    }
}

void split(Node * T, ll k, Node * &L, Node * &R) {
    L = R = nullptr;
    if (!T) return;
    if (T->x < k) {
        split(T->right, k, T->right, R);
        L = T;
    }
    else {
        split(T->left, k, L, T->left);
        R = T;
    }
    recount(L);
    recount(R);
}

Node* insert(Node * T, ll k, ll y) {
    Node* L, * R;
    split(T, k, L, R);
    Node* M = new Node(k, y);
    T = merge(L, merge(M, R));
    recount(T);
    return T;
}

Node* del(Node * T, ll k) {
    Node* L, * R, * RL, * RR;
    split(T, k, L, R);
    split(R, k + 1, RL, RR);
    T = merge(L, RR);
    recount(T);
    return T;
}

bool check(Node * T, ll k) {
	if (!T) return false;
	if (T->x == k) return true;
	if (T->x > k) return check(T->left, k);
	if (T->x < k) return check(T->right, k);
}

ll next(Node *T, ll k) {
    ll res = inf;
    if (T == nullptr) return inf;
    if (T->x > k) {
        res = T->x;
        res = min(res, next(T->left, k));
    }
    if (T->x <= k) {
        res = min(res, next(T->right, k));
    }
    return res;
}

ll prev(Node * T, ll k) {
    ll res = -inf;
    if (T == nullptr) return -inf;
    if (T->x >= k) {
        res = max(res, prev(T->left, k));
    }
    if (T->x < k) {
        res = T->x;
        res = max(res, prev(T->right, k));
    }
    return res;
}

ll kth(Node *T, ll k) {
    ll x = get_sz(T->left);
    if (x > k - 1) return kth(T->left, k);
    else if (x == k - 1) return T->x;
    else return kth(T->right, k - x - 1);
}

signed main() {
    Node* tree = nullptr;
    string s;
    ll x;
    while (cin>>s){
        cin>>x;
        if (s == "insert") {
            if (!check(tree, x))
            tree = insert(tree, x, rand());
        }
        else if (s == "delete")
            tree = del(tree, x);
        else if (s == "next") {
            ll rs = next(tree, x);
            if (rs == inf) cout << "none\n";
            else cout << rs <<"\n";
        }
        else if (s == "prev") {
            ll rs = prev(tree, x);
            if (rs == -inf) cout << "none\n";
            else cout << rs <<"\n";
        }
        else if (s == "kth") {
            if (get_sz(tree) < x) cout << "none\n";
            else cout << kth(tree, x) << "\n";
        }
        else{
            if(check(tree, x))cout<<"true\n";
            else cout<<"false\n";
        }
    }
	return 0;
}
