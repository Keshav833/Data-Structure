
class Solution {
  public:
    bool dfsCheck(int node , vector<vector<int>> adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it :adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,adj, vis, pathVis)==true) return true;
            }
            else if(pathVis[it]){
                return true;
            }   
        }
        pathVis[node]=0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if( !vis[i]){
                
            if(dfsCheck(i,adj,vis,pathVis)==true)
            return true;
            }
            
            
        }
        return false;
        
        
    }
};