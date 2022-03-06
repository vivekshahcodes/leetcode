class LRUCache {
public:
    int maxCapacity, currSize = 0;
    unordered_map<int,int> m;
    unordered_map<int,list<int>::iterator> address;
    list<int> l;
    
    LRUCache(int capacity) {
        maxCapacity = capacity;
    }
    
    int get(int key) {
        if(m.count(key)==0){
            return -1;
        }
        list<int>::iterator it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            list<int>::iterator it = address[key];
            l.erase(it);
            address.erase(key);
            m.erase(key);
            currSize -= 1;
        }
        
        if(currSize==maxCapacity){
            int last = l.back();
            l.pop_back();
            address.erase(last);
            m.erase(last);
            currSize -= 1;
        }
        
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
        currSize += 1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
