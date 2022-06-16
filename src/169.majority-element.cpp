/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // (1) sort
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // return nums[n/2];
        
        // // (2) hash_table
        // unordered_map<int,int> map;
        // int majority = 0, count = 0;
        // for(int i: nums){
        //     map[i]++;
        //     if(map[i] > count){
        //         majority = i;
        //         count = map[i];
        //     }
        // }
        // return majority;
        
        // (3)Boyer-Moore vote
        int candidate = nums[0];
        int count = 0;
        for(int num:nums){
            if(num == candidate){
                count++;
            }else{
                count --;
                if(count == 0){
                    candidate = num;
                    count++;
                }
            }
        }
        return candidate;
    }
};
// @lc code=end

