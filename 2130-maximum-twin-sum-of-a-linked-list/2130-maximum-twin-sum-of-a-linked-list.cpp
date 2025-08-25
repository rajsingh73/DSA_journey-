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
        ListNode * fast=head;
        ListNode * slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode * prev;
        while(slow){
            ListNode * nextslow=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextslow;
        }
        ListNode * first=head;
        ListNode * second=prev;
        int ans=0;
        while(first && second){
            ans=max(ans,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return ans;
    }
};