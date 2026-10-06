class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        int length = 0;

      
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        int pos = length - n;

    
        if (pos == 0) {
            return head->next;
        }


        temp = head;

        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }


        temp->next = temp->next->next;

        return head;
    }
};