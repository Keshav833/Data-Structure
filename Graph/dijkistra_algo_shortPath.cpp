class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto it :edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        // shortest distance src to that vertices
        vector<int> dis(V, INT_MAX);
        dis[src]= 0;
        
        //priority queue <dis,vertices>
        priority_queue< pair<int,int> ,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>
                        > pq;
                        
        pq.push({0,src});
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int d = node.first;
            int u = node.second;
            if(d>dis[u]) continue;
            for(auto it:adj[u]){
                int v = it.first;
                int wt = it.second;
                if(dis[v]>dis[u]+wt){
                   dis[v]=dis[u]+wt;
                pq.push({dis[v],v});
                }
            }
        
        }
        
        return dis;
        
        
        
    }
};