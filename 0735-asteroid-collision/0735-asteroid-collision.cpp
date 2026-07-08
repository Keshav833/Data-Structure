class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for( int curr:asteroids){
            bool alive = true;
            while(alive && !st.empty() && st.top()>0 && curr<0){
                if( st.top() < abs(curr)){
                    st.pop();
                }
                else if ( st.top() > abs(curr)){
                    alive = false;
                    break;
                }
                else{
                    st.pop();
                    alive = false;
                    break;
                }
            }

            if( alive){
                st.push(curr);
            }
        }
        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};