/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
                // (1) recursion
//         if (root == nullptr){
//             return nullptr;
//         }
//         TreeNode* tmp = root->left;
//         root->left = root -> right;
//         root->right = tmp;
        
//         invertTree(root->left);
//         invertTree(root->right);
        
//         return root;
        
        // (2) bfs
        if (root == nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* cur_node = q.front();
            TreeNode* tmp = cur_node->left;
            cur_node->left = cur_node->right;
            cur_node->right = tmp;
            q.pop();
            if (cur_node->left != nullptr){
                q.push(cur_node->left);
            }
            if (cur_node->right != nullptr){
                q.push(cur_node->right);
            }
        }
        return root;
    }
};
// @lc code=end

