/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        res.emplace_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        
        for (int i = startIndex; i < nums.size(); ++i) {
            path.emplace_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // (1) Cascading  time:O(n*2^n)  space:O(n*2^n)
    //     vector<vector<int>> res;
    //     res.emplace_back(vector<int>{});
    //     vector<int> tmp;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int cur = nums[i];
    //         int res_size = res.size();
    //         for (int j = 0; j < res_size; ++j) {
    //             tmp = res[j];
    //             tmp.emplace_back(cur);
    //             res.emplace_back(tmp);
    //         }
    //     }
    //     return res;
    // }
        
        // (2) Backtracking time:O(n*2^n)  space:O(n)
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

