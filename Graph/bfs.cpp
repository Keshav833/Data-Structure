class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
       vector<int> vist(v, 0);
        vist[0] = 1;
        queue<int> q;
        vector<int> bfs;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vist[it]){
                    vist[it]=1;
                    q.push(it);
                    
                }
            }
            
        }
        return bfs;
        
        
    }
};