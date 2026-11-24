class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen  =1;
        long long maxlcm =1;
        for( int i:nums){
            maxlcm = lcm(maxlcm , (long long)i);
        }
        long long maxVal = *max_element(nums.begin(),nums.end());
        long long limit = maxlcm *maxVal;
        for (int i=0;i<n;++i){
            long long prod = 1;
            long long g =0;
            long long l =1;
            for( int j =i ;j<n;++j){
                if(prod>limit /nums[j]) break;
                prod*=nums[j];
                g = gcd(g,(long long)nums[j]);
                l = lcm(l,(long long)nums[j]);

                if(prod == g * l){
                    maxlen = max(maxlen,j-i+1);
                }
            }

        }
        return maxlen;
    }
};