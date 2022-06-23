/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointers
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int short_line = 0;
        while(left < right){
            short_line = min(height[left],height[right]);
            int cur_area = short_line*(right - left);
            if(cur_area > area){
                area = cur_area;
            }
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return area;
    }
};
// @lc code=end

