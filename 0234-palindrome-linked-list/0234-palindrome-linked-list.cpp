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
    ListNode * rev(ListNode *head){
        ListNode * temp=head;
        ListNode * prev=NULL;
        while(temp!=NULL){
            ListNode * t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode * fast=head;
        ListNode * low=head;
        while(fast!=NULL){
            if(fast->next==NULL){
                fast=NULL;
                ListNode * temp=low->next;
                low->next=NULL;
                low=temp;
                continue;
            }
            fast=fast->next->next;
            if(fast==NULL){
                ListNode * temp=low->next;
                low->next=NULL;
                low=temp;
            }
            else low=low->next;
        }
        ListNode * mid=rev(low);
        low=head;
        while(mid!=NULL){
            if(low->val!=mid->val) return false;
            low=low->next;
            mid=mid->next;
        }
        return true;
    }
};