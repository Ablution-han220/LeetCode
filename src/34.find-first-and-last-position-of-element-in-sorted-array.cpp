/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftborder = -2;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle - 1;
                leftborder = right;
            } else {
                left = middle + 1 ;
            }
        }
        return leftborder;
    }

    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightborder = -2;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
                rightborder = left;
            }
        }
        return rightborder;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftborder = getLeftBorder(nums,target);
        int rightborder = getRightBorder(nums,target);
        if (leftborder == -2 || rightborder == -2) {
            return {-1,-1};
        }
        if (rightborder - leftborder > 1) {
            return {leftborder+1,rightborder-1};
        }
        return {-1,-1};    
    }
};
// @lc code=end

