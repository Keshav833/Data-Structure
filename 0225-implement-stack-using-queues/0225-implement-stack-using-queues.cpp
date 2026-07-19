class MyStack {
        queue<int>  q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        while(s!=0 && s>0){
            int front = q.front();
            q.pop();
            q.push(front);
            s--;
        }
    }
    
    int pop() {
        int p = q.front();
        q.pop();
        return p;
    }
    
    int top() {
        if(q.size()==0){
            return 0;
        }
        else{
            return q.front();
        }
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */