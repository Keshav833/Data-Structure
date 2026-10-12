class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // for( int i =0; i < n ;i++){
        //     for( int j = i+1 ; j < n;j++){
        //         if( nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        unordered_map<int , int > mp;
        for( int i =0; i < n ; i++){
            int needed = target - nums[i];

            //find 
            if(mp.find(needed) != mp.end()){
                return {mp[needed],i};

            // write both if exist 
            }
            
            mp.insert({nums[i], i});
            // add to mp if not 
            
        }

        return {-1,-1};
    }
};