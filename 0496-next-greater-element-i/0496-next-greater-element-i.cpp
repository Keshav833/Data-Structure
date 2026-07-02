class Solution {
public:
    int isFound(int curr , vector<int> & nums1){
        for(int i =0; i < nums1.size();i++){
            if( nums1[i] == curr){
                return i;
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans(nums1.size());

        for(int i=nums2.size()-1;i>=0;i--){
            int curr = nums2[i];
            if(st.empty()){
                st.push(curr);
                int idx = isFound(curr, nums1);
                if(idx!=-1){
                    ans[idx]=-1;
                }
            }
            else{
                while(!st.empty() && st.top()<=curr){
                    st.pop();
                }
                //  int idx = isFound(curr, nums2);
                 if(st.empty()){
                    st.push(curr);
                    int idx = isFound(curr, nums1);
                if(idx!=-1){
                    ans[idx]=-1;
                }
                 }
                else{
                     int idx = isFound(curr, nums1);
                if(idx!=-1){
                    ans[idx]=st.top();
                }
                    st.push(curr);
                }
               
            }
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};