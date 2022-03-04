class Node {
    public:
    int value;
    Node* next;
    
    Node(int x){
        value = x;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    int len = 0;
    
    MyLinkedList() {
        head = NULL;
        len = 0;
    }
    
    int get(int index) {
        if(index>=len || index<0){
            return -1;
        }
        Node* curr = head;
        
        for(int i=0;i<index;i++){
            curr = curr->next;
        }
        return curr->value;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        len++;
    }
    
    void addAtTail(int val) {
        Node* curr = head;
        for(int i=0;i<len-1;i++){
            curr = curr->next;
        }
        Node* temp = new Node(val);
        if(curr==NULL){
            head = temp;
            len++;
            return;
        }
        curr->next = temp;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
        }else if(index==len){
            addAtTail(val);
        }else if(index>0 && index<len){
            Node* curr = head;
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            Node* temp = new Node(val);
            temp->next = curr->next;
            curr->next = temp;
            len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=len || index<0){
            return;
        }
        
        if(index==0){
            Node* temp = head;
            head = head->next;
            delete temp;
            len--;
        }else if(index==len-1){
            Node* curr = head;
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = NULL;
            delete temp;
            len--;
        }else{
            Node* curr = head;
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            len--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
