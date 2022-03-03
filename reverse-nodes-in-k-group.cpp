/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(temp==NULL) return head;
            temp = temp->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode;
        
        int i=1;
        
        while(curr!=NULL && i<=k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            i++;
        }
        
        if(nextNode!=NULL){
            head->next = reverseKGroup(nextNode,k); 
        }
        
        return prev;
        
    }
};
