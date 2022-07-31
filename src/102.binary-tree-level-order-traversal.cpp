/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    // (2) dfs time:O(n) space:O(n)
    void dfs(vector<vector<int>>& res, TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (level >= res.size()) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        dfs(res, root->left, level + 1);
        dfs(res, root->right, level + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        // (1) bfs time:O(n) space:O(n)
    //     if (root == nullptr) {
    //         return {};
    //     }
    //     vector<vector<int>> res;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         int lvl_size = q.size();
    //         vector<int> lvl_node;
    //         while (lvl_size > 0) {
    //             TreeNode* cur = q.front();
    //             q.pop();
    //             if (cur->left != nullptr) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right != nullptr) {
    //                 q.push(cur->right);
    //             }
    //             lvl_node.push_back(cur->val);
    //             --lvl_size;
    //         }
    //         res.push_back(lvl_node);
    //     }
    //     return res;
    // }
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        dfs(res,root,0);
        return res;
    }
};
// @lc code=end

