/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_set<int>& st) {
        if (root == nullptr) return;

        if (st.find(root->val) == st.end()) {
            st.insert(root->val);
        }

        dfs(root->left, st);
        dfs(root->right, st);
    }

    int numColor(TreeNode* root) {
        unordered_set<int> ans;
        dfs(root, ans);
        return ans.size();
    }
};