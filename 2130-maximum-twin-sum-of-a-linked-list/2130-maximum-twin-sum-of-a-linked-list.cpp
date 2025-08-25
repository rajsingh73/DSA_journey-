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
        int size=0;
        ListNode * temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        return size;
    }
    int pairSum(ListNode* head) {
        int n=s(head);
        vector<int> store(n/2);
        int size=0;
        int ans=0;
        ListNode * temp=head;
        while(temp){
            if(size<n/2) store[size]=temp->val;
            else{
                int prev=n-1-size;
                ans=max(ans,temp->val+store[prev]);
            }
            size++;
            temp=temp->next;
        }
        return ans;
        
    }
};