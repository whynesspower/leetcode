    // We are using dummy value of nodes for front and back node
    // the node in the head is the dummy node, value 0, next, prev pointing to null
    // same is the last node. We do this so that we don't have to check null condition 
    // on updating the value of the nodes. 

class Node {
public:
    // Strcuture of the node which is needed. 
    int key, value;
    Node *prev, *next;
    Node() : key(0), value(0), prev(NULL), next(NULL) {}
    Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    // The doubly linked list will maintain the order of nodes 
    // The order of recently used keys. 
    // The older keys will be behind, newer keys will be in front in the DLL
    
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key) {
        if (nodes.find(key) == nodes.end()) {
            return -1;
        }
    // 
        update(nodes[key]);
        return nodes[key] -> value;
    }
    
    void put(int key, int value) {
        if (nodes.find(key) != nodes.end()) {
            nodes[key] -> value = value;
            update(nodes[key]);
        } else {
            Node* node = new Node(key, value);
            nodes[key] = node;
            add(node);
            if (size == capacity) {
                popBack();
            } else {
                size++;
            }
        }
    }
private:
    int capacity, size;
    unordered_map<int, Node*> nodes;
    Node *head = new Node(), *tail = new Node();
    
    void add(Node* node) {
        Node* next = head -> next;
        head -> next = node;
        node -> next = next;
        node -> prev = head;
        next -> prev = node;
    }
    
    void remove(Node* node) {
        // 
        Node *prev = node -> prev, *next = node -> next;
        prev -> next = next;
        next -> prev = prev;
    }
    
    void update(Node* node) {
        remove(node);
        add(node);
    }
    
    void popBack() {
        Node* node = tail -> prev;
        remove(node);
        nodes.erase(node -> key);
        delete node;
    }
};