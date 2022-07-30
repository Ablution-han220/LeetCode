/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
//         // (1) top to bottom
//         if (root == nullptr){
//             return true;
//         }
//         int differ = abs(height(root->left)-height(root->right));
//         // Three necessary conditions for height-balanced binary tree.
//         // 1. current tree is satisfied.
//         // 2. left subtree of current tree is satisfied.
//         // 3. right subtree of current tree is satisfied.
//         if(differ <= 1 && isBalanced(root->left) && isBalanced(root->right)){
//             return true;
//         }
//         return false;
//     }
    
//     int height(TreeNode* root){
//         if(root == nullptr){
//             return 0;
//         }else{
//             return max(height(root->left),height(root->right)) + 1;
//         }
//     }
        
        // (2) bottom to top
        if (root == nullptr){
            return true;
        }
        if (height(root) >= 0){
            return true;
        }
        return false;
    }
    
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
            return -1;
        }else{
            return max(leftHeight,rightHeight) + 1;
        }
    }
};
// @lc code=end

