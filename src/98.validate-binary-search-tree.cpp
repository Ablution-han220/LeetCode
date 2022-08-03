/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    struct Qnode{
        TreeNode* node;
        long long upper, lower;
    };
    
    bool isValidBST(TreeNode* root) {
        //(1) bfs with valid range time:O(n) space:O(n)
        queue<Qnode> q;
        q.emplace(Qnode{root, LLONG_MAX, LLONG_MIN});
        while (!q.empty()) {
            Qnode qnode = q.front();
            q.pop();
            TreeNode* node = qnode.node;
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (node->val <= qnode.lower || node->val >= qnode.upper) {
                return false;
            }
            if (left != nullptr) {
                q.emplace(Qnode{left, node->val, qnode.lower});
            }
            if (right != nullptr) {
                 q.emplace(Qnode{right, qnode.upper, node->val});
            }
        }
        return true;
    }
    
        // (2) dfs with valid range
//     bool dfs(TreeNode* root, long long low, long long high) {
//         if (root == nullptr) {
//             return true;
//         }
//         if (root->val <= low || root->val >= high) {
//             return false;
//         }
//         return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
//     }

//     bool isValidBST(TreeNode* root) {
//         return dfs(root, LLONG_MIN, LLONG_MAX);
//     }
    
    // (3) Recursive with inorder traversal
//     TreeNode* prev = nullptr;
    
//     bool inorder(TreeNode* root) {
//         if (root == nullptr) {
//             return true;
//         }
//         if (!inorder(root->left)) {
//             return false;
//         }
//         if (prev != nullptr && root->val <= prev->val) {
//             return false;
//         }
//         prev = root;
//         return inorder(root->right);
//     }
    
//     bool isValidBST(TreeNode* root) {
//         return inorder(root);
//     }
    
        // (4) Iterative inorder traversal
    // bool isValidBST(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     TreeNode* prev = nullptr;
    //     while (!st.empty() || root != nullptr) {
    //         while (root != nullptr) {
    //             st.push(root);
    //             root = root->left;
    //         }
    //         root = st.top();
    //         st.pop();
    //         if (prev != nullptr && root->val <= prev->val) {
    //             return false;
    //         }
    //         prev = root;
    //         root = root->right;
    //     }
    //     return true;
    // }
};
// @lc code=end

