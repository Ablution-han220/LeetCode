/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp bottom to up  time:O(s*n) space:O(s) where s is teh amount, n is denomination count
        // dp[i] = min(dp[i-ci]) + 1
        int max = amount + 1;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int coin : coins) {
                if ( i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == (amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end

