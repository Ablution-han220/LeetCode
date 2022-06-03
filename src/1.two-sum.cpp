/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force
        // for(int i = 0 ; i< nums.size(); i++){
        //      for(int j = i+1 ; j< nums.size(); j++){
        //          int a = nums[i];
        //          if(nums[j] == (target - nums[i])){
        //              return {i,j};
        //          }
        //     }
        // }
        // return {};
        
        // hashmap
        unordered_map<int,int> store;
        for(int i = 0 ; i< nums.size(); i++){
            auto it = store.find(target-nums[i]);
            if(it != store.end()){
                return {it->second,i};
            }
            store[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

