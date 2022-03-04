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
    
    ListNode* findMid(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* firstList, ListNode* secondList){
        
        if(firstList==NULL){
            return secondList;
        }
        
        if(secondList==NULL){
            return firstList;
        }
        
        ListNode* mergedList;
        
        if(firstList->val < secondList->val){
            mergedList = firstList;
            mergedList->next = merge(firstList->next,secondList);
        }else{
            mergedList = secondList;
            mergedList->next = merge(firstList,secondList->next);
        }
        
        return mergedList;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* midNode = findMid(head);
        ListNode* firstHalf = head;
        ListNode* secondHalf = midNode->next;
        midNode->next = NULL;
        
        firstHalf = sortList(firstHalf);
        secondHalf = sortList(secondHalf);
        
        ListNode* sortedList = merge(firstHalf,secondHalf);
        return sortedList;
        
    }
};
