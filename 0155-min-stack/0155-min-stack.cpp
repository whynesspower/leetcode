class MinStack {
public:
    stack<int>st;
    stack<int>dscSt;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            dscSt.push(val);
            return;
        }
        st.push(val);
        if(dscSt.top()>=val){
            dscSt.push(val);
        }
    }
    
    void pop() {
        if(st.top()==dscSt.top()){
            // st.pop();
            dscSt.pop();
            return st.pop();
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return dscSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */