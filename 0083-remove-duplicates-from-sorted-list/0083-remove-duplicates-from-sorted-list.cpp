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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy=new ListNode(-1);
        ListNode * ans=dummy;
        ListNode  * temp=head;
        while(temp){
            int val=temp->val;
            ans->next=temp;
            ans=ans->next;
            temp=temp->next;
            while(temp && temp->val==val) temp=temp->next;
        }
        ans->next=NULL;
        return dummy->next;
        
    }
};