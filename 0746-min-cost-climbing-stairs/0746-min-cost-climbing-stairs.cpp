class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> sh(n,INT_MAX);
        sh[0] = cost[0];
        sh[1] = cost[1];

        for( int i =2;i<n;i++){
            sh[i]=min(sh[i-1],sh[i-2])+cost[i];
        }
        
        return min(sh[n-1],sh[n-2]);


    }
};