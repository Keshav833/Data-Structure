class MinStack {
        int mini;
        stack<pair<int, int>> st;

public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {

        // mini = min( value , mini);
        if( st.empty()){
        st.push({value, value});
        }
        else
        st.push({value, min(value , st.top().second)});
    }
    
    void pop() {
        
        st.pop();
        // mini = st.top().second;
        
    }
    
    int top() {

        if(st.size()==0){
            return 0;
        }

       return  st.top().first;
    }
    
    int getMin() {
        if(st.size()==0){
            return 0;
        }
       return  st.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */