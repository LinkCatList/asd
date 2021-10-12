#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sort(a) sort(a.begin(), a.end())
const int SIZE = 1e5 + 10;
vector<int> adj[SIZE];
vector<int> adj2[SIZE];
bool usd[SIZE];
bool usd2[SIZE];
int n, m, f, s, u, v, cnt = 0;
vector<int> comp;
vector<int> comp2;


void input() {
    scanf("%d %d", &n, &m);
    while (m--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

}
void dfs(int cur) {
  usd[cur] = true;
  comp.push_back(cur);
  for (int i=0;i<adj[cur].size();++i) {
    int nxt = adj[cur][i];
    if (!usd[nxt])
      dfs(nxt);
  }
}
void dfs2(int cur2) {
  usd2[cur2] = true;
  comp2.push_back(cur2);
  for (int i = 0;i<adj2[cur2].size();++i) {
    int nxt2 = adj2[cur2][i];
    if (!usd2[nxt2])
      dfs2(nxt2);
  }
}

int main(){
    input();
    for (int i = 1; i<=n; ++i) {
    if (!usd2[i]) {
      dfs2(i);
      cnt++;
    }
  }
  cout<<cnt<<"\n";
  for (int i = 1; i<=n; ++i) {
    if (!usd[i]) {
        comp.clear();
      dfs(i);
      cout<<comp.size()<<"\n";
      sort(comp);
      for(int j = 0; j<comp.size(); j++){
        cout<<comp[j]<<" ";
      }
      cout<<"\n";
    }
  }
    return 0;
}
