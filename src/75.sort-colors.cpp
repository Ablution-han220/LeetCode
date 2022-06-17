/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
//         // (1) quick sort
//         int left = 0, right = nums.size() - 1;
//         quickSort(nums,left,right); 
//     }
    
//     void quickSort(vector<int>& nums, int left, int right){
//         if(left<right){
//             int pivot = partition(nums,left,right);
//             quickSort(nums,left,pivot - 1);
//             quickSort(nums,pivot + 1,right);
//         }
//     }
    
//     int partition(vector<int>&nums,int left,int right){
//         int x = nums[right];
//         int p = left - 1;
//         for(int i = left; i < right; i++){
//             if(nums[i] <= x){
//                 p++;
//                 swap(nums[i],nums[p]);
//             }
//         }
//         swap(nums[p+1],nums[right]);
//         return p+1;
//     }   
        // (2) two-pointers
        int n = nums.size();
        int p0 = 0;
        int p2 = n - 1;
        for(int i = 0; i <= p2; i++){
            while(i<= p2 && nums[i] == 2){
                swap(nums[i],nums[p2]);
                p2--;  
            } 
            if(nums[i] == 0){
                swap(nums[i],nums[p0]);
                p0++;
            }
        }
    }
};
// @lc code=end

