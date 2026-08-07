class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* next = NULL;

        slow->next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //Weave the two halves
        ListNode* first = head;
        ListNode* second = prev;
        ListNode* next1 = NULL;
        ListNode* next2 = NULL;

        while (second != NULL) {
            next1 = first->next;
            next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};