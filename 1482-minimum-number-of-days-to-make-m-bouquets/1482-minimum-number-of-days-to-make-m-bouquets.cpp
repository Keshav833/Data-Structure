class Solution {
public:
    bool canMake(vector<int>& bloomDay, int day, int m, int k){
        int bouqets = 0;
        int cnt=0;

        for(int b:bloomDay){
            if( b<=day){
                cnt++;
            }
            else{
                bouqets+= cnt/k;
                cnt=0;
            }
        }
        bouqets+= cnt/k;
        return  bouqets>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) m*k> bloomDay.size()) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end()) ;
        int r = *max_element(bloomDay.begin(), bloomDay.end()) ;
        int ans=0;
        // sort(bloomDay.begin(), bloomDay.end());
        
        while( l <= r){
            int mid = l + (r-l)/2;
            if(canMake(bloomDay,mid,m,k)){
                r = mid-1;
                ans = mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};