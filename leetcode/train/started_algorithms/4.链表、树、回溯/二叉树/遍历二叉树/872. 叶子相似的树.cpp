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
    void leaf(TreeNode* root, vector<int>& res) {
        //1.终止条件: 走到空节点, 直接返回      (在任何二叉树的递归函数中, 第一行永远应该是, 如下述所示的"判空", 这是二叉树递归的安全基石.)
        if (root == nullptr) return;

        //2.前序位置: 在这里更新 result        (其后, 在前序位置(或其他位置), 可做进一步的其他判断)
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(root->val);
            return;
        }

        //3.递归遍历左右子树
        leaf(root->left, res);
        leaf(root->right, res);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        leaf(root1, ans1);
        leaf(root2, ans2);
        if (ans1 == ans2) {
            return true;
        }
        else {
            return false;
        }
    }
};