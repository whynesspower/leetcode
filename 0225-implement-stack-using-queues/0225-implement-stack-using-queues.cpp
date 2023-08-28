class MyStack {
    private:
    std::queue<int> q1;
    std::queue<int> q2;
    int topElement;
public:
    MyStack() {
    }
    
    void push(int x) {
        if(!q1.empty() || (q1.empty()==true and q2.empty()==true ) ){
            q1.push(x);
            topElement=x;
        }
        else{
            q2.push(x);
            topElement=x;
        }
    }
    
    int pop() {
        bool flag=false;
        while(!q1.empty()){
            int a = q1.front();
            q1.pop();
            if(q1.empty()){
                return a;
            }
            topElement=a;
            q2.push(a);
        }
        while(!q2.empty()){
            int a= q2.front();
            q2.pop();
            if(q2.empty()){
                return a;
            }
            topElement=a;
            q1.push(a);
        }
        return -1;
    }
    
    int top() {
        return topElement;
    }
    
    bool empty() {
        return (q1.size()==0 and q2.size()==0);
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