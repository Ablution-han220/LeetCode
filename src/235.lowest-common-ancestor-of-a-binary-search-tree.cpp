/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // dfs using the property of binary search tree
        // which is left child_value < root_value < right child_value
        if (root == nullptr) {
            return nullptr;
        }
        int root_val = root->val;
        // p,q in left subtree
        if (p->val < root_val && q->val < root_val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        // p,q in right subtree
        if (p->val > root_val && q->val > root_val) {
            return lowestCommonAncestor(root->right,p,q);
        }
        // else the output must be root
        return root;
    }
};
// @lc code=end

