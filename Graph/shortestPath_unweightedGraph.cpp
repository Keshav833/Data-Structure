class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>  adj(V);
        for( auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if( dist[node]!=INT_MAX){
                
            for(auto it:adj[node]){
                if(dist[it] > dist[node]+1){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
            }
        }
        for(auto& it:dist){
            if(it==INT_MAX){
                it = -1;
            }
        }
        return dist[dest];
    }
};
