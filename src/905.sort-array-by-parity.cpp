/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            while(left < right && nums[left] % 2 == 0) {
                left++;
            }
            while(left < right && nums[right] % 2 == 1) {
                right--;
            }
            if(left < right) {
                swap(nums[left++], nums[right--]);
            }
        }
        return nums;
    }
};
// @lc code=end

