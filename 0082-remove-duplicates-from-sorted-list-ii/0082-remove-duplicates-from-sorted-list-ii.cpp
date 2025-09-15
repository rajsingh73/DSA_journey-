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
        ListNode * temp=head;
        while(temp!=NULL){
            int val=temp->val;
            ListNode * tempp=temp;
            temp=temp->next;
            if(temp && temp->val==val){
                while(temp && temp->val==val) temp=temp->next;
            }
            else{
                ans->next=tempp;
                ans=ans->next;
            }
        }
        ans->next=NULL;
        return dummy->next;
        
    }
};