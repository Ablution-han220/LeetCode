/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // for loop
        // int low = 0;
        // int high = nums.size() - 1;
        // while(low <= high){
        //     // Notice！！int overflow
        //     int middle = low + (high - low) / 2;
        //     // int middle = (low + high) / 2;
        //     if(target < nums[middle]){
        //         high = middle - 1;
        //     }else if(target > nums[middle]){
        //         low = middle + 1;
        //     }else{
        //         return middle;
        //     }
        // }
        // return -1;
        
        // recursion
        int low = 0;
        int high = nums.size() - 1;
        int index = binarySearch(nums,target,low,high);
        if(index == -1){
            return -1;
        }
        return index;
    }
    
    int binarySearch(vector<int>& nums,int target, int low, int high){
        if(low <= high){
            int middle = low + (high - low) / 2;
            if(target < nums[middle]){
                return binarySearch(nums,target,low,middle - 1);
            }else if(target > nums[middle]){
                return binarySearch(nums,target,middle + 1,high);
            }else{
                return middle;
            }
        }
        return -1;
    }
};
// @lc code=end

