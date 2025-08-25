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
    int s(ListNode * head){
        ListNode * temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int size=s(head);
        if(size==1) return NULL;
        size=size/2;
        int temps=1;
        ListNode* front=head->next;
        ListNode * prev=head;
        while(front!=NULL){
            if(temps==size){
                prev->next=front->next;
                delete(front);
                break;
            }
            front=front->next;
            prev=prev->next;
            temps++;
        }
        return head; 
    }
};