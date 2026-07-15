class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (prev->val == curr->val) {
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};