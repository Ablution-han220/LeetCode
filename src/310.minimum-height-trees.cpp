/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // (1) Topological sorting time:O(n) space:O(n)
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adjacent(n);
        for (vector<int>& edge: edges) {
            int start = edge[0], end = edge[1];
            adjacent[start].emplace_back(end);
            adjacent[end].emplace_back(start);
            ++degree[start];
            ++degree[end];
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.emplace(i);
            }
        }
        int remainNode = n;
        while (remainNode > 2) {
            int level_size = q.size();
            remainNode -= level_size;
            for (int i = 0; i < level_size; ++i) {
                int cur = q.front();
                q.pop();
                for (int &neighbor : adjacent[cur]) {
                    --degree[neighbor];
                    if (degree[neighbor] == 1) {
                        q.emplace(neighbor);
                    }
                }
            }
        }
        while (!q.empty()) {
            res.emplace_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

