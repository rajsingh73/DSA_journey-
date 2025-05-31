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
    ListNode * merge(ListNode * first,ListNode * second){
        if(first==NULL) return second;
        if(second==NULL) return first;
        ListNode * dummy=new ListNode(-1);
        ListNode * temp=dummy;
        while(first!=NULL && second!=NULL){
            if(first->val<=second->val){
                temp->next=first;
                first=first->next;
                temp=temp->next;
            }
            else{
                temp->next=second;
                second=second->next;
                temp=temp->next;
            }
        }
        while(first){
            temp->next=first;
            first=first->next;
            temp=temp->next;
        }
        while(second){
            temp->next=second;
            second=second->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        if(lists.size()==0) return NULL;
        for(int i=0;i<lists.size();i++){
            dummy->next=merge(dummy->next,lists[i]);
        }
        return dummy->next;
    }
};