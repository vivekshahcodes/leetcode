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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* curr = head;
        while(curr!=NULL){
            while(curr->next!=NULL && curr->val==curr->next->val){
                ListNode *nextNode = curr->next;
                curr->next = nextNode->next;
                delete nextNode;
            }
            curr = curr->next;
        }
        
        return head;
    }
};
