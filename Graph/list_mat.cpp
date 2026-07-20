class Solution {
  public:
    vector<vector<int>> adjToMat(vector<vector<int>>& adj) {
        // code here
        int n = adj.size();
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        
        for(int i=0;i< n;i++){
            for(int j =0;j< adj[i].size();j++){
                int sec = adj[i][j];
                mat[i][sec] =1;
            }
        }
        return mat;
        
        
    }
};