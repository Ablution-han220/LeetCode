/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }
    
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = height(root->left);
        int right_height = height(root->right);
        diameter = max(diameter,left_height + right_height);
        // int res = left_height + right_height;
        // if (res > diameter) {
        //     diameter = res;
        // }
        return max(left_height,right_height) + 1;
    }
};
// @lc code=end

