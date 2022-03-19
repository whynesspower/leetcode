class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int, stack<int>>st;
    int maxfreq=0;
    
    void push(int val) {
        maxfreq=max(maxfreq, ++freq[val]);
        st[freq[val]].push(val);
    }
    
    int pop() {
        int x= st[maxfreq].top();
        st[maxfreq].pop();
        if(st[freq[x]--].size()==0) maxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */