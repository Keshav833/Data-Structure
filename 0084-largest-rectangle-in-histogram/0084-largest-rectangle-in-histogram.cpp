class Solution {
public:
    vector<int> PrevSmall(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> ans;
        for(int i =0;i< n;i++){
            // if(st.empty()){
            //     st.push(i);
            //     ans.push_back(-1);
            // }
            while(!st.empty() && heights[st.top()]>=heights[i] ){
                st.pop();
            }
            if(st.empty()){
                // st.push(heights[i]);
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
                st.push(i);
        }
        return ans;
    }
    vector<int> nextSmall(vector<int>& heights){
         int n = heights.size();
        stack<int> st;
        vector<int> ans;
        for(int i =n-1;i>=0;i--){
            // if(st.empty()){
            //     st.push(i);
            //     ans.push_back(n);
            // }
            while(!st.empty() && heights[st.top()]>=heights[i] ){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(n);
            }
            else{
                
                ans.push_back(st.top());
            }
                st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int rect = 0;
        vector<int> pse = PrevSmall(heights);
        vector<int> nse = nextSmall(heights);
        for(int i =0;i < heights.size();i++){
            int area = heights[i] * (nse[i]-pse[i] -1);
            rect = max( rect,area );
        }
        return rect;
    }
};