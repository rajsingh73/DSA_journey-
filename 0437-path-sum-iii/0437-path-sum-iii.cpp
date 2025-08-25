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
    int dfs(TreeNode* root, long long curr, int target, unordered_map<long long,int>& mp) {
        if (!root) return 0;

        curr += root->val;
        int ans = 0;
        if (mp.count(curr - target)) ans += mp[curr - target];

        mp[curr]++;
        ans += dfs(root->left, curr, target, mp);
        ans += dfs(root->right, curr, target, mp);
        mp[curr]--; // backtrack

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        mp[0] = 1; // base case: prefix sum = 0
        return dfs(root, 0, targetSum, mp);
    }
};
