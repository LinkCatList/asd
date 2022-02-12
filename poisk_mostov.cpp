  void dfs(ll u, ll h_u, ll parent){
    used[u] = true;
    up[u] = h[u];
    for(auto v:adj_list[u]){
        if(!used[v]){
            dfs(v, h_u+1, u){
                up[u] = min(up[u], up[v]);
            }
        }
        else{
            up[u] = min(up[u], h[v]);
        }
    }
    if(up[u]>=h[u]){
        cout<<u<<" "<<parent;
    }
}
