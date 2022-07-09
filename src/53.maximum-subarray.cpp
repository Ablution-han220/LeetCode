/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//         // greedy
//         int tmp = 0;
//         int res = INT_MIN;
        
//         for(int i = 0; i < nums.size(); i++){
//             tmp += nums[i];
//             if (tmp > res) {
//                 res = tmp;
//             }
//             if (tmp < 0) {
//                 tmp = 0;
//             }
//         }
//         return res;
//     }
        
        // dp
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        
        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if (dp[i] > res) {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end

