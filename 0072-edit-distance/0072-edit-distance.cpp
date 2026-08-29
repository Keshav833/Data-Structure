class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> mat(n+1, vector<int>(m+1,0));
        for(int i =0; i <=n;i++){
            mat[i][0]=i;
        }
        for(int i =0; i <=m;i++){
            mat[0][i]=i;
        }
        for(int i =1; i <=n;i++){
            for(int j =1; j <=m;j++){
                if(word1[i-1]==word2[j-1]){
                    mat[i][j]=mat[i-1][j-1];
                }
                else{
                    mat[i][j]= 1 + min(mat[i-1][j-1],min(mat[i][j-1],mat[i-1][j]));
                }
            }
        }
        return mat[n][m];
    }
};