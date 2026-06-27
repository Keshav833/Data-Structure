class Solution {
public:
    bool canSolve(vector<int>& weights, int days, int mid){
        int w=0;
        int d=1;
        for( int i =0;i<weights.size();i++){
            if( w + weights[i] >mid){
                w=weights[i];
                d++;
            }else{

            w+=weights[i];
            }

        }
        return d <=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for( int n :weights){
            r+=n;
        }
        int ans=r;
        while( l<=r){
            int mid = l + (r-l)/2;
            if( canSolve(weights, days, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};