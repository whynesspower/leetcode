class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int a = q1.size();
        int b = q1.size()-1;
        while(a-1){
            q2.push(q1.front());
            q1.pop();
            a--;
        }
        int ans = q1.front();
        q1.pop();
        while(b){
            q1.push(q2.front());
            q2.pop();
            b--;
        }
        return ans;  
    }
    
    int top() {
        int a = q1.size();
        int b = q1.size();
        while(a-1){
            q2.push(q1.front());
            q1.pop();
            a--;
        }
        int ans=q1.front();
        q2.push(ans);
        q1.pop();
        while(b){
            q1.push(q2.front());
            q2.pop();
            b--;
        }
        return ans;
    }
    
    bool empty() {
        return q1.empty();
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