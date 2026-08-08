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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //reverse
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //delete nth node from start.
        ListNode* prev1 = NULL;
        ListNode* head1 = prev;
        ListNode* curr1 = prev;  //reversed head
        ListNode* next1 = NULL;

        for(int i = 1; i < n; i++) {
            next1 = curr1->next;
            prev1 = curr1;
            curr1 = next1;
        }
         if (prev1 == NULL) {
            head1 = curr1->next;
        }
        else {
            prev1->next = curr1->next;
        } //removed


        //reverse again.
        ListNode* prev2 = NULL;
        ListNode* curr2 = head1;
        ListNode* next2 = NULL;
        while(curr2 != NULL) {
            next2 = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = next2;
        }
        return prev2;
    }
};