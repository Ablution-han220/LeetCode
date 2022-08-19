/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // dp  time:O(m*n)  space:O(m) where mm is the \text{subSetSum}subSetSum, and nn is the number of array elements
        int n = nums.size();
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int subSum = sum / 2;
        vector<bool> dp(subSum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            int cur = nums[i];
            for (int j = subSum; j >= cur; --j) {
                dp[j] = dp[j] || dp[j - cur];
            }
        }
        return dp[subSum];
    }
};
// @lc code=end

