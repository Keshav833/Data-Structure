class Solution {
public:
    bool canSolve(vector<int> & nums, int k , int mid){
        int sum = nums[0];
        int sub = 1;
        for(int i =1;i<nums.size();i++){
            if( nums[i] + sum > mid){
                sub++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return sub<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        if( nums.size()< k) {
            return -1;
        }
        // sort( nums.begin(), nums.end());
        int l = *max_element(nums.begin(),nums.end());
        int r = 0;
        for(int n:nums){
            r+=n ;
        }
        int ans = l;
        while( l<=r){
            int mid = l + (r-l)/2;
            if( canSolve(nums, k , mid)){
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