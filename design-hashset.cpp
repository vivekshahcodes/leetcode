class Node {
    public:
    int value;
    Node* next;
    
    Node(int v){
        value = v;
        next = NULL;
    }
};

class MyHashSet {
public:
    int len;
    vector<Node*> v;
    
    
    MyHashSet() {
        len = 1e6+1;
        v.resize(len);
    }
    
    void add(int key) {
        int hash = key%len;
        if(!contains(key)){
            if(v[hash]==NULL){
                v[hash] = new Node(key);
            }else{
                v[hash] -> next = new Node(key);
            } 
        }           
    }
    
    void remove(int key) {
        int hash = key%len;
        Node* curr = v[hash];
        
        if(curr==NULL){
            return;
        }
        
        if(curr->value==key){
            Node* temp = curr;
            curr = temp->next;
            delete temp;
            v[hash] = curr;
        }else{
            while(curr->next->value!=key && curr->next!=NULL){
                curr = curr->next;
            }
            
            if(curr->next->value==key){
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                v[hash] = curr;
            }
        }
    }
    
    bool contains(int key) {
        int hash = key%len;
        Node* curr = v[hash];
        while(curr!=NULL){
            if(curr->value==key){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
