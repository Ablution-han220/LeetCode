/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    // (1)dfs time:O(n) space:O(height)
//     int depth(TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         int left_height = depth(root->left);
//         int right_height = depth(root->right);
//         return max(left_height,right_height) + 1;
        
//     }
//     int maxDepth(TreeNode* root) {
//         int res = depth(root);
//         return res;
//     }
    
    // (2)bfs time:O(n) space:O(n)
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int cur_size = q.size();
            while (cur_size > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                cur_size -= 1;
            }
            ++depth;
        }
        return depth;
    }
};
// @lc code=end

