class Solution {
  public:
    void dfs(int src, vector<int> &vis,vector<vector<int>> &adj,stack<int> &st){
        vis[src] = 1;
        for( auto it:adj[src]){
            if(vis[it]!=1){
                dfs(it,vis,adj,st);                
            }
        }
        st.push(src);
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        for( int i =0; i < V;i++){
            if( vis[i]!= 1){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int> path(V,0);
        path[src] = 1;
        // for(int)
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(path[node]!=0){
                
            for(auto it:adj[node]){
                
                path[it]+=path[node];
            }
            }
        }
        return path[dest];
        
        
        
    }
};