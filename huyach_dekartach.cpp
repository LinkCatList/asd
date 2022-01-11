#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    ll key, priority;
    Node *left, *right;
    ll sz;
    ll sum;
};
ll getRand(){
    return rand()*32768+rand();
}
Node *newNode(ll key){
    Node *newNode = new Node{key, getRand(), nullptr, nullptr};
    return newNode;
}
Node *root;
bool search(Node *root, ll key){  // лучше нерекурсивная
    while(root){
        if(root->key == key)return true;
        if(root->key>key)root = root->left;
        else root = root->right;
    }
    return false;
}
void printTree(Node *root, ll h){
    if(!root)return;
    printTree(root->left, h+1);
    for(ll i = 0; i<h; i++){
        cout<<"     ";
    }
    cout<<root->key<<"\n";
    printTree(root->right, h+1);
}
bool searchRecursive(Node *root, ll key){
    if(!root)return false;
    if(root->key == key)return true;
    if(root->key>key)searchRecursive(root->left, key);
    else searchRecursive(root->right, key);
}
pair<Node*, Node*>split(Node *root, ll key){
    if(!root)return make_pair(nullptr, nullptr);
    if(root->key <= key){
        pair<Node*, Node*>p = split(root->right, key);
        root->right = p.second;
        return make_pair(p.first, root);
    }
    else{
        pair<Node*, Node*>p = split(root->left, key);
        root->left = p.second;
        return make_pair(p.first, root);
    }
}
Node *mergeNodes(Node *leftTree, Node *rightTree){
    if(!leftTree)return rightTree;
    if(!rightTree)return leftTree;
    if(leftTree->priority < rightTree->priority){
        leftTree->right = mergeNodes(leftTree->right, rightTree);
        return leftTree;
    }
    else{
        rightTree->left = mergeNodes(rightTree->left, leftTree);
        return rightTree;
    }
}
Node *insert(Node *root, ll key){
    pair<Node*, Node*>p = split(root, key);
    Node *node = newNode(key);
    return mergeNodes(mergeNodes(p.first, node), p.second);
}
Node *erase(Node *root, ll key){
    pair<Node*, Node*>p = split(root, key);
    pair<Node*, Node*>p2 = split(p.first, key-1);
    delete p2.second;
    return mergeNodes(p2.first, p.second);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
