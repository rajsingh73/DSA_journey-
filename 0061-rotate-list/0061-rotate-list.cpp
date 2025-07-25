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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int size=0;
        ListNode * temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        k=k%size;
        if(k==0) return head;
        k=size-k;
        int i=1;
        temp=head;
        while(i<k){
            i++;
            temp=temp->next;
        }
        ListNode * first=temp->next;
        temp->next =NULL;
        temp=first;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=head;
        return first;
    }
};