class Node{
public:
    Node *prev,*next;
    string value;
        
    Node(string v){
        prev = NULL;
        value = v;
        next = NULL;
    }
};

class BrowserHistory {
public:
    Node* curr;
    
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = curr->next;
        while(temp!=NULL){
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        for(int i=0;i<steps;i++){
            if(curr->prev==NULL){
                break;
            }
            curr = curr->prev;
        }
        
        return curr->value;
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;i++){
            if(curr->next==NULL){
                break;
            }
            curr = curr->next;
        }
        
        return curr->value;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
