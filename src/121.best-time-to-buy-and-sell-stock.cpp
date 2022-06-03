/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // one_pass retrieve
//         int max_profit = 0;
//         int buy_price = 0;
//         for(int i = 0;i < prices.size(); i++){
//             if(i == 0){
//                 buy_price = prices[i];
//             }
//             else if(prices[i] < buy_price){
//                 buy_price = prices[i];
//             }else{
//                 int cur_profit = prices[i] - buy_price;
//                 if(cur_profit > max_profit){
//                     max_profit = cur_profit;
//                 }
//             }

//         }
//         return max_profit;
        
        //dynamic programming
        int size = prices.size();
        if (size == 0 ){
            return 0;
        }
        int buy_price = prices[0];
        vector<int> dp(size,0);
        for(int i = 1;i < size;i++){
            buy_price = min(buy_price,prices[i]);
            dp[i] = max(dp[i-1],prices[i] - buy_price);
        }
        return dp[size-1];
    }
};
// @lc code=end

