class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        
        pq.push({0,0}); // {dis,src}
        vector<int> dis(V,INT_MAX);
        vector<long long> way(V,0);
        
        dis[0] = 0;
        way[0] = 1;
        
        while(!pq.empty()){
            auto node = pq.top();
            
            int d = node.first;
            int u = node.second;
            
            pq.pop();
            
            if(dis[u]!=INT_MAX){
            for( auto it:adj[u]){
                    
                    int v  = it.first;
                    int wt = it.second;
                    
                    
                    
                    if(dis[v]>dis[u]+wt){
                        
                        dis[v]=dis[u]+wt;
                        way[v]=way[u];
                        pq.push({v,wt});
                    }
                    else if( dis[v]>dis[u]+wt){
                        way[v]+=way[u];
                        
                    }
                        
                
                
                }
            }
            
        }
        return way[V-1];
    }
};