/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums, int first){
        if (first == nums.size()) {
            res.emplace_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); ++i) {
            swap(nums[first],nums[i]);
            dfs(res, nums, first + 1);
            swap(nums[first],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // backtracking time:O(n * n!) space:O(n * n!)
        vector<vector<int>> res;
        dfs(res, nums, 0);
        return res;
    }
};
// @lc code=end

