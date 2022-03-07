/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        unordered_map<Node*,Node*> m;
        
        while(curr!=NULL){
            Node* newNode = new Node(curr->val);
            m[curr] = newNode;
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr!=NULL){
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        
        return m[head];
    }
};
