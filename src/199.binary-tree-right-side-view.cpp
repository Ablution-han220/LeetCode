/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        // bfs time:O(n) space:O(D) where DD is a tree diameter
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int level_size = q.size();
            while (level_size > 0) {
                TreeNode* cur_node = q.front();
                q.pop();
                if (level_size == 1) {
                    res.emplace_back(cur_node->val);
                }
                if (cur_node->left != nullptr) {
                    q.emplace(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    q.emplace(cur_node->right);
                }
                --level_size;
            } 
        }
        return res;
    }
};
// @lc code=end

