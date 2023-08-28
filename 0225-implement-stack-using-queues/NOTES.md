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
​
/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/
```