class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
    vector<int> ans(n);
        for(int i =(2*n)-1;i>=0;i--){
            int curr = nums[i%n];
            if(st.empty()){
                st.push(curr);
                ans[i%n]= -1;
            }
            else{
                while(!st.empty() && st.top()<=curr){
                    st.pop();
                }
                if( i<n){

                    if(st.empty()){
                        ans[i%n]=-1;
                    }
                    else{
                        ans[i%n]=st.top();
                        // st.push(curr);
                    }
                }
                    st.push(curr);
            }

        }
    return ans;
    }
};