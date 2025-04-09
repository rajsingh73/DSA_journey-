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
    void solve(ListNode * list1,ListNode * list2  , ListNode * &ans){
        if(list1==NULL && list2==NULL) return;
        if(list1==NULL){
            ans->next=new ListNode(list2->val);
            solve(list1,list2->next,ans->next);
            return;
        }
        if(list2==NULL){
            ans->next=new  ListNode(list1->val);
            solve(list1->next,list2,ans->next);
            return;
        }
        if(list1->val<=list2->val){
            ans->next=new  ListNode(list1->val);
            solve(list1->next,list2,ans->next);
        }
        else{
            ans->next=new  ListNode(list2->val);
            solve(list1,list2->next,ans->next);
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ans=new ListNode(-1);
        ListNode * temp=ans;
        solve(list1,list2,ans);
        return temp->next;
    }
};