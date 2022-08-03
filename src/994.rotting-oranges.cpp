/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs time:O(n*m) space: O(n*m)
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir{{-1,0}, {0,1}, {1,0}, {0,-1}};
        int fresh = 0;
        int time = -1;
        queue<pair<int,int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i,j);
                } else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }
        // mark the round   i.e the ticker of timestamp
        q.emplace(-1,-1);
        while (!q.empty()) {
            pair<int,int> x = q.front();
            q.pop();
            if (x.first == -1) {
                ++time;
                if (!q.empty()) {
                    q.emplace(-1,-1);
                }
            } else {
                for (int i = 0; i < 4; ++i) {
                    int row = x.first + dir[i][0];
                    int col = x.second + dir[i][1];
                    if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        --fresh;
                        q.emplace(row,col);
                    }
                }  
            }
        }
        if (fresh == 0) {
            return time;
        }
        return -1;
    }
};
// @lc code=end

