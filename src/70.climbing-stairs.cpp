/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // dp time:O(n) space:O(n)
    //     if (n == 1) {
    //         return 1;
    //     }
    //     vector<int> dp(n + 1,0);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; ++i) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }
        // dp time:O(n) space:O(1)
        if (n == 1) {
            return 1;
        }
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
           int tmp = dp[1] + dp [2];
           dp[1] = dp[2];
           dp[2] = tmp;
        }
        return dp[2];
    }
};
// @lc code=end

