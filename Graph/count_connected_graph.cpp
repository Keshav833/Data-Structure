class Solution {
  public:
    void dfs(vector<int>& vist,int i,const vector<vector<int>>& adj){
        vist[i] = 1;
        
        for(auto it :adj[i]){
            if(!vist[it]){
                dfs(vist,it,adj);
            }
        }
        
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vist(V,0);
        int count = 0;
        for(int i =0;i < V;i++){
            if( vist[i] == 0){
                count++;
                dfs(vist, i,adj);
            }
        }
        return count;
    }
};