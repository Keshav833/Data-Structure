class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> sufix;
        int p=1 ;
        for( int i :nums){
            p*=i;
            prefix.push_back(p);
        }
        int s = 1;
        for( int i =nums.size()-1;i>=0;i--){
            s*=nums[i];
            sufix.insert(sufix.begin(),s);
        }
        vector<int> ans(nums.size());
        ans[0]=sufix[1];
        ans[nums.size()-1]= prefix[nums.size()-2];
        for( int i =1; i <nums.size()-1;i++){
            ans[i]= prefix[i-1] * sufix[i+1];
        }
        return ans;
    }
};