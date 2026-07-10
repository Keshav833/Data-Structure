class Solution {
public:
    vector<int> nextSmall(vector<int> &scale){
        vector<int> ans;
        stack<int> st;
        for(int i =scale.size()-1;i>=0;i--){
            while(!st.empty() && scale[st.top()] >= scale[i]){
                st.pop();
            }
            if(st.empty()){
                
                ans.push_back(scale.size());
                
            }
            else{

                ans.push_back(st.top());
            }
                st.push(i);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
    vector<int> preSmall(vector<int> &scale){
        vector<int> ans;
        stack<int> st;
        for(int i =0;i<scale.size();i++){
            while(!st.empty() && scale[st.top()] >= scale[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
                
                
            }
            else{

                ans.push_back(st.top());
            }
                st.push(i);
        }

        // reverse(ans.begin(), ans.end());

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c =  matrix[0].size();
        vector<int> scale(c,0);
        int rect = 0;
        for(int i =0;i<r;i++){
            int s = 0;
            for(int j =0;j<c;j++){
                if(matrix[i][j]=='1'){
                    scale[j]++;
                }
                else{
                    scale[j]=0;
                }
            }
        vector<int> pse = preSmall(scale);
        vector<int> nse = nextSmall(scale);

        for( int i =0;i<scale.size();i++){
            int area = scale[i] * (nse[i] - pse[i] -1);
            rect = max( rect, area);
        }
                
        }
        
        return rect;
        
    }
};