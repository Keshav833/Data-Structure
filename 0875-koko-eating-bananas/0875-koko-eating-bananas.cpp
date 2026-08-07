class Solution {
public:
    bool canEat(int n,vector<int>& piles, int h){
        long long count =0;
        for( auto i:piles){
            count+= (ceil((double)i/n));
        }
        return count <=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
     int l = 1;
     int r = *max_element(piles.begin(),piles.end());
     int ans = r;
     while( l<=r){
        int mid = l + (r-l)/2;

        if( canEat(mid,piles,h) == true ){
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