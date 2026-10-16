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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        ListNode* slow = head;
        ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
           st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;

}
     
        int sum=0;
        int max_sum=0;
        while(slow!=NULL){
            sum=0;
            sum=(slow->val)+st.top();
            st.pop();
            slow=slow->next;
         max_sum=max(max_sum,sum);
        }
        return max_sum;

    }
};