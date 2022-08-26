/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
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
    // void inorder(TreeNode* root, vector<int>& res) {
    //     if (root == nullptr) {
    //         return;
    //     }
    //     // if (res.size() == k) {
    //     //     return;
    //     // }
    //     inorder(root->left, res);
    //     res.emplace_back(root->val);
    //     inorder(root->right, res);       
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     // (1) inorder recursion time:O(n) space:O(n)
    //     vector<int> res;
    //     inorder(root, res);
    //     return res[k - 1];
    // }
       
        // (2) inorder iterative time:O(H + k) space:O(H) where H is a tree height
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            --k;
            if (k == 0) {
                break;
            }
            root = root->right;
        }
        return root->val;
    }
};
// @lc code=end

