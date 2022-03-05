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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode* curr = NULL;
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* head;
        
        while(first!=NULL && second!=NULL){
            int x = first->val+second->val+carry;
            if(curr==NULL){
                curr = new ListNode(x%10);
                head = curr;
            }else{
                curr->next = new ListNode(x%10);
                curr = curr->next;
            }
            carry = x/10;
            first = first->next;
            second = second->next;
        }
        
        while(first!=NULL){
            int x = first->val+carry;
            curr->next = new ListNode(x%10);
            curr = curr->next;
            carry = x/10;
            first = first->next;
        }
        
        while(second!=NULL){
            int x = second->val+carry;
            curr->next = new ListNode(x%10);
            curr = curr->next;
            carry = x/10;
            second = second->next;
        }
        
        if(carry){
            curr->next = new ListNode(carry);
        }
        
        return head;
    }
};
