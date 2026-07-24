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

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left)
            tail->next = left;
        else
            tail->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // Base Case
        if (head == NULL || head->next == NULL)
            return head;

        // Find Middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        prev->next = NULL;

        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge sorted halves
        return merge(left, right);
    }
};