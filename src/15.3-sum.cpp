/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty() || nums.size() < 3){
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i,j,k;
        for(i = 0; i < n - 2; i++){
            if(nums[i] > 0){
                break;
            }
            // core!
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            j = i + 1;
            k = n - 1;
            while(j < k){
                int target = nums[i] + nums[j] + nums[k];
                if(target < 0){
                    j++;
                }else if(target > 0){
                    k--;
                }else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

