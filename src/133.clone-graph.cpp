/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> visit;
    Node* cloneGraph(Node* node) {
        // (1) dfs time:O(n) space:O(n)
        if (node == nullptr) {
            return node;
        }
        if (visit.find(node) != visit.end()) {
            return visit[node];
        }
        Node* copy_node = new Node(node->val);
        visit[node] = copy_node;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            Node* copy_neighbor = cloneGraph(node->neighbors[i]);
            copy_node->neighbors.push_back(copy_neighbor);
        }
        return copy_node;
    }
        // (2) bfs time:O(n) space:O(n)
    //     if (node == nullptr) {
    //         return node;
    //     }
    //     queue<Node*> q;
    //     q.emplace(node);
    //     visit[node] = new Node(node->val);
    //     while (!q.empty()) {
    //         Node* cur_node = q.front();
    //         q.pop();
    //         for (int i = 0; i < cur_node->neighbors.size(); ++i) {
    //             if (visit.find(cur_node->neighbors[i]) == visit.end()) {
    //                 visit[cur_node->neighbors[i]] = new Node(cur_node->neighbors[i]->val);
    //                 q.emplace(cur_node->neighbors[i]);
    //             }
    //             visit[cur_node]->neighbors.emplace_back(visit[cur_node->neighbors[i]]);
    //         }
    //     }
    //     return visit[node];
    // }
};
// @lc code=end

