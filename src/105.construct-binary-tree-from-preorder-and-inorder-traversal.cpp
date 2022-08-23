/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    // (1) recursion time:O(n) space:O(n)
    int preorderIndex;
    unordered_map<int, int> inorderIndex;
    TreeNode* build(const vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }     
        int rootval = preorder[preorderIndex];
        ++preorderIndex;
        TreeNode* root = new TreeNode(rootval);

        root->left = build(preorder, left, inorderIndex.find(rootval)->second - 1);
        root->right = build(preorder, inorderIndex.find(rootval)->second + 1, right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

