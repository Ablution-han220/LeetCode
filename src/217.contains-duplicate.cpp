/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // // hash_table
        // unordered_map<int,int> map;
        // for(int i = 0; i< nums.size(); i++){
        //     auto isfind = map.find(nums[i]);
        //     if(isfind != map.end()){
        //         return true;
        //     }
        //     map[nums[i]] = i;
        // }
        // return false;
        
        // set
        unordered_set<int> map;
        for(int num:nums){
            if(map.find(num) != map.end()){
                return true;
            }
            map.insert(num);
        }
        return false;
    }
};
// @lc code=end

