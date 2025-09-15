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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode * downdummy=new ListNode(-1);
        ListNode * updummy=new ListNode(-1);
        ListNode * down=downdummy;
        ListNode * up=updummy;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                down->next=temp;
                down=down->next;
            }
            else{
                up->next=temp;
                up=up->next;
            }
            temp=temp->next;
        }
        down->next=NULL;
        up->next=NULL;
        down->next=updummy->next;
        return downdummy->next;
        
    }
};