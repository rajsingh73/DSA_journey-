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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> findMiddle(ListNode* start,ListNode*end){
        int count=1;
        ListNode * head=start;
        while(head!=end) {
            head=head->next;
            count++;
        }
        ListNode * prev=NULL;
        head=start;
        int newcount=1;
        if(count%2==1) count++;
        count=count/2;
        while(newcount<count){
            newcount++;
            prev=head;
            head=head->next;
        }
        cout<<head->val<<endl;
        return {prev,head,head->next};
    }
    TreeNode* solve(ListNode * start,ListNode * end){
        if(start==NULL || end==NULL) return NULL;
        if(start==end) return new TreeNode(start->val);
        vector<ListNode*> v=findMiddle(start,end);
        TreeNode * root=new TreeNode(v[1]->val);
        root->left=solve(start,v[0]);
        root->right=solve(v[2],end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* end=head;
        while(end->next!=NULL){
            end=end->next;
        }
        return solve(head,end);
    }
};