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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *first, *slow = head, *fast = head;
        
        for(int i=1;i<k;i++){
            fast = fast->next;
        }
        
        first = fast;
        
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        swap(slow->val,first->val);
        
        return head;
    }
};
