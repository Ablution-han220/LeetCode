/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // vector<vector<int>> res(m,vector<int>(n,0));
        
        // bfs
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (mat[i][j] == 0) {
                    q.emplace(i,j);
                } else {
                    mat[i][j] = INT_MIN;
                }
            }
        }
        
        while(!q.empty()){
             int x = q.front().first;
             int y = q.front().second;
             q.pop();
             // left
             if (x - 1 >= 0 && x < m && y >= 0 && y < n && mat[x-1][y] == INT_MIN) {
                 mat[x-1][y] = mat[x][y] + 1;
                 q.emplace(x-1,y);
             }
             // right 
             if (x >= 0 && x + 1 < m && y >= 0 && y < n && mat[x+1][y] == INT_MIN) {
                 mat[x+1][y] = mat[x][y] + 1;
                 q.emplace(x+1,y);
             }
            // up
             if (x >= 0 && x < m && y >= 0 && y + 1 < n && mat[x][y+1] == INT_MIN) {
                 mat[x][y + 1] = mat[x][y] + 1;
                 q.emplace(x,y+1);
             }
            // down
             if (x >= 0 && x < m && y - 1>= 0 && y < n && mat[x][y-1] == INT_MIN) {
                 mat[x][y - 1] = mat[x][y] + 1;
                 q.emplace(x,y-1);
             }
        }
        return mat;
        
        
        // dfs
    }  
};
// @lc code=end

