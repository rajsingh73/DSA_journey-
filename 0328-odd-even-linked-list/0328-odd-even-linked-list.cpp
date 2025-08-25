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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode * oddindex=head;
        ListNode*  evenhead=head->next;
        ListNode * evenindex=head->next;
        ListNode * view=head->next->next;
        while(view){
            oddindex->next=view;
            oddindex=oddindex->next;
            view=view->next;
            evenindex->next=view;
            evenindex=evenindex->next;
            if(view) view=view->next;
        }
        oddindex->next=evenhead;
        return head;
        
    }
};