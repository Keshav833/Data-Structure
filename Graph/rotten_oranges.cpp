class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int tm=0;
        for(int i =0;i < n;i++){
            for(int j =0; j< m ; j++){
                if( mat[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm= max(t,tm);
            for(int i =0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    vis[nrow][ncol]!=2 && mat[nrow][ncol]==1 ){
                        vis[nrow][ncol] =2;
                        q.push({{nrow,ncol},t+1});
                    }
                
            }
            
        }
        
        for(int i =0; i < n;i++){
            for(int  j =0;j < m ; j++){
                if( vis[i][j]==0 && mat[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
        
        
    }
};