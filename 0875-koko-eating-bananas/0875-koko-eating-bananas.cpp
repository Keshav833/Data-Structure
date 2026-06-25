class Solution {
public:
    bool canEat(vector<int>& piles,int mid, int h){
        double sum=0;
        for(int n:piles){
            sum+=ceil((double)n/mid);
        }
        return sum<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans= r;
        while( l<=r){
            int mid = l+(r-l)/2;
            if( canEat( piles,mid,h)){
                ans = min(ans,mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;

    }
};