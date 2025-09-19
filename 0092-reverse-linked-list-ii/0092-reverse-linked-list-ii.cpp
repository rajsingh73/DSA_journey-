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
    ListNode * solve(ListNode * head,int right,int count){
        ListNode * prev=NULL;
        ListNode * temp=head;
        while(temp && count<=right){
            ListNode * t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
            count++;
        }
        head->next=temp;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int count=1;
        ListNode * temp=head;
        ListNode * prev=NULL;
        while(temp && count<left){
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(prev){
            prev->next=solve(temp,right,count);
            return head;
        }
        return solve(temp,right,count);
    }
};