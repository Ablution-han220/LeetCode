/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         // (1) product of prefix and suffix
//         int n = nums.size();
//         vector<int> prefix(n,0);
//         vector<int> suffix(n,0);
//         prefix[0] = 1;
//         suffix[n-1] = 1; 
//         for(int i = 1; i< n;i++){
//             prefix[i] = prefix[i-1] * nums[i-1];
//         }
//         for(int j = n-2; j >= 0; j--){
//             suffix[j] = suffix[j+1] * nums[j+1];
//         }
        
//         vector<int> res;
//         for(int i = 0; i < n; i++){
//             res.push_back(prefix[i] * suffix[i]);
//         }
//         return res;
        // (2) o(1) space complexity
        int n = nums.size();
        vector<int> res(n,0);
        res[0] = 1;
        for(int i = 1; i< n;i++){
            res[i] = res[i-1] * nums[i-1];
        }
        int R = 1;
        for(int j = n-1; j >= 0; j--){
            res[j] = res[j] * R;
            R = R*nums[j];
        }
        return res;
    }
};
// @lc code=end

