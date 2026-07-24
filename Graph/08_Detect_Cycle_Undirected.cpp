class Solution {
  public:
    bool detect(int src,vector<int>& vis,vector<vector<int>>& adj){
        vis[src]=1;
        queue<pair<int,int>> q;
        //pair(node,parent)
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return true;
                }
            }
            
        }
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        int E = edges.size();
       for(int i = 0; i < E; i++){
   adj[edges[i][0]].push_back(edges[i][1]);
   adj[edges[i][1]].push_back(edges[i][0]);
}
        vector<int> vis(V,0);
        
        for(int i =0;i< V;i++){
            if( vis[i]!=1){
                if( detect(i,vis,adj)==true) return true;
            }
        }
        
        return false;
        
        
        
        
    }
};