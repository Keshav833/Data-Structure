

class Solution {
  public:
    void trav(int start,vector<int>& vist,vector<int>& ds, vector<vector<int>> &adj){
        vist[start]=1;
        ds.push_back(start);
        for(auto it :adj[start]){
            if(!vist[it]){
            trav(it,vist,ds,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vist(n,0);
        vector<int>  ds;
        int start = 0;
        trav(start,vist,ds,adj);
        return ds;
    }
};


// visit node
// ↓
// store node
// ↓
// visit every unvisited neighbour
// ↓
// return