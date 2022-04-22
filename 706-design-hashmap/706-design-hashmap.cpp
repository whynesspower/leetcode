class MyHashMap {

    private: 
    vector<int>key;
    vector<int>value;
    
    public:
    MyHashMap(): key(1e6+1, -1) {
        // value(1e6+1, -1);
    }
    
    void put(int x, int y) {
        key[x]=y;
    }
    
    int get(int x) {
        return key[x];
    }
    
    void remove(int x) {
        key[x]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */