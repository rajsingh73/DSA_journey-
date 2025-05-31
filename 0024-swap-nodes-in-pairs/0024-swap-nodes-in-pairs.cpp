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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode * temp=head;
        ListNode * prev=new ListNode(-1);
        int count=1;
        while(temp!=NULL){
            if(count%2==0){
                int val=prev->val;
                prev->val=temp->val;
                temp->val=val;
            }
            prev=temp;
            temp=temp->next;
            count++;
        }
        return head;
        
    }
};