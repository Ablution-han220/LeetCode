/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    const vector<vector<int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1,0}};
    bool backtracking(vector<vector<char>>& board, vector<vector<int>>& visited, string& word, int i, int j, int pos) {
        if (board[i][j] != word[pos]) {
            return false;
        } else if (pos == word.size() - 1) {
            return true;
        }
        visited[i][j] = 1;
        int m = board.size();
        int n = board[0].size();
        bool res = false;
        for (int d = 0; d < dir.size(); ++d) {
            int row = i + dir[d][0];
            int col = j + dir[d][1];
            if (row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == 0) {
                res = backtracking(board, visited, word, row, col, pos + 1);
                if (res == true) {
                    return true;
                }
            }
        }
        visited[i][j] = 0;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        // backtracking time:O(mn*3^L) space:O(mn)
        int m = board.size();
        int n = board[0].size();
        if (word.size() > m*n) {
            return false;
        }
        bool res = false;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = backtracking(board, visited, word, i, j, 0);
                if(res == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

