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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            n++;
        }

        k %= n;

        while (k > 0) {
            ListNode* curr = head;
            ListNode* last = head->next;

        
            while (last->next != nullptr) {
                curr = curr->next;
                last = last->next;
            }

            curr->next = nullptr;  
            last->next = head;    
            head = last;          
            k--;
        }

        return head;
    }
};