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
    void dfs(TreeNode* root, set<int>& st) {
        if (root == nullptr) return;

        if (st.find(root->val) == st.end()) {
            st.insert(root->val);
        }

        dfs(root->left, st);
        dfs(root->right, st);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        dfs(root, ans);
        if (ans.size() >= 2) {
            auto it = ans.begin();
            it++;
            return *it;
        }
        else {
            return -1;
        }
    }
};