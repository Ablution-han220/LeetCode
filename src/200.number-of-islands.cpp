/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
//         // bfs
//         int m = grid.size();
//         int n = grid[0].size();
//         int n_island = 0;
    
//         for(int i = 0; i < m; i++){
//            for(int j = 0; j < n; j++){
//                 if (grid[i][j] == '1') {
//                     n_island++;
//                     grid[i][j] = '0';
//                     queue<pair<int,int>> q;
//                     q.emplace(i,j);
//                     while(!q.empty()){
//                         int x = q.front().first;
//                         int y = q.front().second;
//                         q.pop();
//                         // left
//                         if (x - 1 >= 0 && grid[x-1][y] == '1') {
//                             q.emplace(x - 1,y);
//                             grid[x-1][y] = '0';
//                         }
//                         // right 
//                         if (x + 1 < m && grid[x+1][y] == '1') {
//                             q.emplace(x + 1,y);
//                             grid[x+1][y] = '0';
//                         }
//                         // up 
//                         if (y - 1 >= 0 && grid[x][y-1] == '1') {
//                             q.emplace(x,y - 1);
//                             grid[x][y - 1] = '0';
//                         }
//                         // down
//                         if (y + 1 < n && grid[x][y + 1] == '1') {
//                             q.emplace(x,y + 1);
//                             grid[x][y + 1] = '0';
//                         }
//                     }
//                 }          
//            }
//         }
//         return n_island;
//     }
        
        // dfs
        int n_island = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == '1') {
                    n_island++;
                    dfs(grid,i,j);
                }
            }
        }
        return n_island;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
            return;
        }
        grid[x][y] = '0';
        // left, right, up, down
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
    }
};
// @lc code=end

