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
    void dfs(TreeNode* root, int& dep) {
        if (root == nullptr) return;

        dfs(root->left, dep);
        dfs(root->right, dep);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int ans = 1;
        dfs(root, ans);
        return ans;
    }
};