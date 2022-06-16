/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // backtracking
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int>combination;
        dfs(target,candidates,res,combination,0);
        return res;
        
    }
    
    void dfs(int target, vector<int>&candidates,vector<vector<int>>&res,vector<int>&combination, int index){
        if(index == candidates.size()){
            return;
        }
        if(target == 0){
            res.emplace_back(combination);
            return;
        }
        // use next num
        dfs(target,candidates,res,combination,index+1);
        // use current num
        target = target - candidates[index];
        if(target >= 0){
            combination.emplace_back(candidates[index]);
            dfs(target,candidates,res,combination,index);
            combination.pop_back();
        }
        
    }
};
// @lc code=end

