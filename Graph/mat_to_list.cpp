class Solution {
  public:
    vector<vector<int>> matToAdj(vector<vector<int>>& mat) {
        // code here
        int V = mat.size();
        vector<vector<int>> ans(V);
        
        for(int i =0;i<V ;i++){
            for(int j = 0 ; j < V;j++){
                
                if(mat[i][j]==1){
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};