class Node {
    public:
    pair<int,int> val;
    Node* next;
    
    Node(pair<int,int> v){
        val = v;
        next = NULL;
    }
};

class MyHashMap {
public:
    int len;
    vector<Node*> v;
    
    MyHashMap() {
        len = 1e6+1;
        v.resize(len);
    }
    
    void put(int key, int value) {
        int hash = key%len;
        Node* curr = v[hash];
        
        if(curr==NULL){
            curr = new Node({key,value});
            v[hash] = curr;
        }else{
            while(curr->next!=NULL && (curr->val).first!=key){
                curr = curr->next;
            }
            
            if((curr->val).first==key){
                (curr->val).second = value;
            }else{
                curr->next = new Node({key,value});
            }
        }
    }
    
    int get(int key) {
        int hash = key%len;
        Node* curr = v[hash];
        
        while(curr!=NULL && (curr->val).first!=key){
            curr = curr->next;
        }
        
        if(curr==NULL){
            return -1;
        }else{
            return (curr->val).second;
        }
        
    }
    
    void remove(int key) {
        
        int hash = key%len;
        Node* curr = v[hash];
        
        if(curr==NULL){
            return;
        }
        
        if((curr->val).first==key){
            v[hash] = curr->next;
            delete curr;
            return;
        }
        
        while(curr!=NULL && (curr->next->val).first!=key){
            curr = curr->next;
        }
        
        if(curr==NULL){
            return;
        }
        
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
