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
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode * temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int ans=0;
        n=n-1;
        temp=head;
        while(temp!=NULL){
            int val=temp->val;
            temp=temp->next;
            ans+=(val*pow(2,n));
            n=n-1;
        }
        return ans;
        
    }
};