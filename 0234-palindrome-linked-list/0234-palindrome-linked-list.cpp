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
    vector<int>ans;
    bool isPalindrome(ListNode* head) {
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        int left=0;
        int right=ans.size()-1;
        while(left<=right){
            if(ans[left]!=ans[right]){
                return false;
            } 
            left++;
            right--;
        }
        return true;
    }
};