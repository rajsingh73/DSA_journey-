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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int ans = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second; // use unsigned to avoid negative shifts
            int first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int currIndex = temp.second - mini; // normalize to prevent overflow
                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;
                if (temp.first->left) q.push({temp.first->left, currIndex * 2 + 1});
                if (temp.first->right) q.push({temp.first->right, currIndex * 2 + 2});
            }
            ans = max(ans, int(last - first + 1));
        }
        return ans;
    }
};
