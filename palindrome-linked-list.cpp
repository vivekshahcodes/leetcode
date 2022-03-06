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

ListNode* reverse(ListNode* head){
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode;
    
    while(curr!=NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

class Solution {
public:
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head, *fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* right = reverse(slow->next);
        ListNode* left = head;
        
        bool flag = true;
        
        while(left!=NULL && right!=NULL){
            if(left->val!=right->val){
                flag = false;
                break;
            }
            left = left->next;
            right = right->next;
        }
        
        reverse(slow->next);
        
        return flag;

    }
};
