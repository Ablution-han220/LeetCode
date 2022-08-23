/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:
    // (1) bfs time:O(n) space:O(n)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         //tree: [v1,v2,null,...]
        queue<TreeNode*> q;
        q.emplace(root);
        string tree = "[";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                tree += "null,";
                continue;
            }
            tree += to_string(node->val) + ",";
            q.emplace(node->left);
            q.emplace(node->right);
        }
        tree.pop_back();
        tree += "]";
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[null]") {
            return nullptr;
        }
        data = data.substr(1, data.size() - 2);
        vector<string> dataArray;
        string str;
        for (char& ch : data){
            if (ch == ',') {
                dataArray.emplace_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.emplace_back(str);
            str.clear();
        }
        queue<TreeNode*> q;
        // string a = dataArray[0];
        TreeNode* root = new TreeNode(stoi(dataArray[0]));
        q.emplace(root);
        int cursor = 1;
        while (cursor < dataArray.size()) {
            TreeNode* node = q.front();
            q.pop();
            string left = dataArray[cursor];
            string right = dataArray[cursor + 1];
            if (left != "null") {
                node->left = new TreeNode(stoi(left));
                q.emplace(node->left);
            }
            if (right != "null") {
                node->right = new TreeNode(stoi(right));
                q.emplace(node->right);
            }
            cursor += 2;
        }
        return root;
    }
    
// public:
//     // (2) preorder dfs time:O(n) space:O(n)
//     // Encodes a tree to a single string.
//     void dfs_serialize(TreeNode*root, string& tree) {
//         if (root == nullptr) {
//             tree += "null,";
//         } else {
//             tree += to_string(root->val) + ",";
//             dfs_serialize(root->left, tree);
//             dfs_serialize(root->right, tree);
//         }
//     }
//     string serialize(TreeNode* root) {
//          //tree: v1,v2,null,...
//         string res;
//         dfs_serialize(root, res);
//         return res;
//     }
//     TreeNode* dfs(list<string>& dataArray) {
//         if (dataArray.front() == "null") {
//             dataArray.erase(dataArray.begin());
//             return nullptr;
//         }
//         TreeNode* root = new TreeNode(stoi(dataArray.front()));
//         dataArray.erase(dataArray.begin());
//         root->left = dfs(dataArray);
//         root->right = dfs(dataArray);
//         return root;                  
//     }
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         list<string> dataArray;
//         string str;
//         for (char& ch : data){
//             if (ch == ',') {
//                 dataArray.emplace_back(str);
//                 str.clear();
//             } else {
//                 str.push_back(ch);
//             }
//         }
//         // if (!str.empty()) {
//         //     dataArray.emplace_back(str);
//         //     str.clear();
//         // }
//         return dfs(dataArray);
//     }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

