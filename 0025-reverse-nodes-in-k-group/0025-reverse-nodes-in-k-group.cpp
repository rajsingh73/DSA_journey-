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
    ListNode * findright(ListNode * head,int k){
        ListNode * right=head;
        int l=1;
        while(right!=NULL && l<k){
            right=right->next;
            l++;
        }
        if(l==k){
            return right;
        }
        else{
            return NULL;
        }
    }
    ListNode * reverse(ListNode * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * newnode= reverse(head->next);
        ListNode * front= head->next;
        front->next=head;
        head->next=NULL;
        return newnode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * left=head;
        ListNode * prevnode=NULL;
        while(left!=NULL){
            ListNode * right = findright(left,k);
            if(right==NULL){
                if(prevnode){
                    prevnode->next=left;
                    break;
                }
            }
            ListNode * lastone = right->next;
            right->next=NULL;
            right= reverse(left);
            if(left==head){
                head=right;
            }
            else{
                prevnode->next=right;
            }
            prevnode = left;
            left=lastone;
        }
        return head;
    }
};