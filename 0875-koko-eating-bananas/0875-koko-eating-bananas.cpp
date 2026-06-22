class Solution {
public:
    bool CanEat(vector<int>& piles, int h, int n){
        double sum=0;
        for(int x:piles){
            sum+=ceil((double)x/n);
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int n:piles){
            r=max(r,n);
        }
        int mini = INT_MAX;
        while( l<=r){
            int mid = l + (r-l)/2;
            if(CanEat(piles,h,mid)){
                mini = min(mini,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini;
    }
};