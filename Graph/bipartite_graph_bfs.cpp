class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vist(V,-1);
        // <node,color>
        queue<pair<int,int>> q;
        vist[0]= 0;
        q.push({0,0});
        while(!q.empty()){
            auto node = q.front();
            int n = node.first;
            int c = node.second;
            q.pop();
            for(auto it :adj[n]){
                if(vist[it] == c){
                    return false;
                }
                // else{
                if( vist[it]==-1){
                    
                    if(c==0 ){
                        vist[it]=1;
                        q.push({it,1});
                    }
                    else{
                        vist[it]=0;
                        q.push({it,0});
                        
                    }
                }
                // }
                
            }
        }
        return true;
        
    }
};