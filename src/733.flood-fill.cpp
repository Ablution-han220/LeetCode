/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    //     // bfs
    //     if (newColor == image[sr][sc]){
    //         return image;
    //     }
    //     int n = image.size();
    //     int m = image[0].size();
    //     vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};
    //     queue<pair<int,int>> q;
    //     q.emplace(sr,sc);
    //     int originColor = image[sr][sc];
    //     while(!q.empty()){
    //         pair<int,int> point = q.front();
    //         image[point.first][point.second] = newColor;
    //         q.pop();
    //         for(int i = 0; i < 4; i++){
    //             int next_x = point.first + direction[i][0];
    //             int next_y = point.second + direction[i][1];
    //             if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m &&
    //                 image[next_x][next_y] == originColor) {
    //                 q.emplace(next_x,next_y);
    //                 // image[next_x][next_y] = newColor;
    //             }
    //         }
    //     }
    //     return image;
    // }
        // dfs
        if (newColor == image[sr][sc]){
            return image;
        }
        dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
        
    }   
    const vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(vector<vector<int>>& image, int x, int y, int originColor, int newColor){
        if(image[x][y] == originColor){
            image[x][y] = newColor;
        }
        for(int i = 0; i < 4; i++){
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x >= 0 && next_x < image.size() && next_y >= 0 && next_y < image[0].size() &&
                image[next_x][next_y] == originColor) {
                dfs(image,next_x,next_y,originColor,newColor);
            }
        }      
    }
};
// @lc code=end

