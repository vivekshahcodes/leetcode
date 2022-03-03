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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode *curr = head;
        int len = 0;
        
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
        
        if(len==1){
            return NULL;
        }
        
        int i = 0, mid = len/2;
        curr = head;
        
        while(i<mid-1){
            curr = curr->next;
            i++;
        }
        
        ListNode *midNode = curr->next;
        curr->next = midNode->next;
        delete midNode;
        
        return head;
        
    }
};
