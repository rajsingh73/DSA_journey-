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
    ListNode* insert(ListNode * head,int data){
        if(head==NULL || head->val>=data){
            ListNode * temp=new ListNode(data);
            temp->next=head;
            head=temp;
            return head;
        }
        head->next=insert(head->next,data);
        return head;

    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(-6000);
        ListNode * temp=head;
        while(temp){
            dummy=insert(dummy,temp->val);
            temp=temp->next;
        }
        return dummy->next;

    }
};