class Solution {
  public:
    void dfs(int src ,vector<int>& vis,vector<vector<pair<int,int>>>& adj, stack<int> &st){
        vis[src]=1;
        for(auto it :adj[src]){
            if(vis[it.first]!=1){
                dfs(it.first, vis, adj,st);
            }   
        }
        
                st.push(src);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i =0; i < V;i++){
            if( vis[i]!=1){
                dfs(i,vis,adj,st);
                // st.push(i);
            }
        }
        
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            auto dist1 = dist[node];
            if( dist[node]!=INT_MAX){
                
            for(auto it:adj[node]){
                auto currd = dist1 + it.second ;
              
                    
                dist[it.first] = min(dist[it.first],currd);
             
                
            }
            }
            st.pop();
        
        }
        
        
        for(auto &it :dist){
            if( it == INT_MAX){
                it = -1;
            }
        }
        return dist;
        
        
        
        
    }
};
 