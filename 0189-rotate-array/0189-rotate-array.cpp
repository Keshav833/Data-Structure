class Solution {
public:
    void rev(vector<int> & ar,int l , int r ){
        while(l < r){
            int temp = ar[l] ;
            ar[l] = ar[r];
            ar[r] = temp;
            l++;
            r--;
        }

    }

    vector<int> rotate(vector<int>& nums, int k) {
        // int l = 0;
        int n = nums.size();
        
        k = k % n;
        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);    
        return nums;

    

    }
};