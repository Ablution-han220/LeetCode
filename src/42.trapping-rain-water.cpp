/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // (1) two pointers time:O(n) space:O(1)
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > left_max) {
                    left_max = height[left];
                }
                res += left_max - height[left];
                ++left;
            } else {
                if (height[right] > right_max) {
                    right_max = height[right];
                }
                res += right_max - height[right];
                --right;
            }
        }
        return res;
    }
        
        // (2) dp time:O(n) space:O(n)
    //     int size = height.size();
    //     vector<int> left_max(size);
    //     vector<int> right_max(size);
    //     int res = 0;
    //     left_max[0] = height[0];
    //     for (int i = 1; i < size; ++i) {
    //         left_max[i] = max(left_max[i - 1], height[i]);
    //     }
    //     right_max[size - 1] = height[size - 1];
    //     for (int j = size - 2; j >= 0; --j) {
    //         right_max[j] = max(right_max[j + 1], height[j]);
    //     }
    //     for (int i = 0; i < size; ++i) {
    //         res += min(left_max[i], right_max[i]) - height[i];
    //     }                                
    //     return res;    
    // }
        
        // (3) stack time:O(n) space:O(n)
    //     int res = 0, current = 0;
    //     stack<int> stk;
    //     while (current < height.size()) {
    //         while (!stk.empty() && height[current] > height[stk.top()]) {
    //             int top = stk.top();
    //             stk.pop();
    //             if (stk.empty()) {
    //                 break;
    //             }
    //             int dist = current - stk.top() - 1;
    //             int bar_height = min(height[current], height[stk.top()]) - height[top];
    //             res += dist * bar_height;
    //         }
    //         stk.push(current);
    //         ++current;
    //     }
    //     return res;
    // }
};
// @lc code=end

