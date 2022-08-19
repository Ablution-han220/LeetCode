/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // (1) Mark Visited Elements time:O(m*n) space:O(1)
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     // four direction:right, down, left, up6*
    //     vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    //     vector<int> res;
    //     int visited = 101;
    //     int row = 0;
    //     int col = 0;
    //     int dirIndex = 0;
    //     for (int i = 0; i < m*n; ++i) {
    //         int cur = matrix[row][col];
    //         res.emplace_back(cur);
    //         matrix[row][col] = visited;
    //         int next_row = row + direction[dirIndex][0];
    //         int next_col = col + direction[dirIndex][1];
    //         if (next_row < 0 || next_row >= m || next_col < 0 || next_col >= n || 
    //             matrix[next_row][next_col] == visited) {
    //             dirIndex = (dirIndex + 1) % 4;
    //         }
    //         row += direction[dirIndex][0];
    //         col += direction[dirIndex][1];
    //     }
    //     return res;
    // }
        
        // (2) set up boundaries time:O(m*n) space:O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        vector<int> res;
        while (res.size() < m*n) {
            for (int col = left; col <= right; ++col) {
                res.emplace_back(matrix[top][col]);
            }
            for (int row = top + 1; row <= down; ++row) {
                res.emplace_back(matrix[row][right]);
            }
            if (top != down) {
                for (int col = right - 1; col >= left; --col) {
                     res.emplace_back(matrix[down][col]);
                }
            }
            if (left != right) {
                for (int row = down - 1; row > top; --row) {
                     res.emplace_back(matrix[row][left]);
                }
            }
            ++top;
            --down;
            ++left;
            --right;
        }
        return res;
    }
};
// @lc code=end

