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
    void solve(ListNode* head,int val,ListNode* ans){
        if(head==NULL) return;
        if(head->val==val){
            solve(head->next,val,ans);
            return;
        }
        ans->next=new ListNode(head->val);
        solve(head->next,val,ans->next);
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummy=new ListNode(-1);
        ListNode* ans=dummy;
        solve(head,val,ans);
        return dummy->next;
    }
};