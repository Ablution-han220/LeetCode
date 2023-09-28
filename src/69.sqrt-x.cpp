/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 2;
        int right = x;
        while (left <= right) {
            long int middle = left + (right - left) / 2;
            if (middle < x / middle) {
                left = middle + 1;
            } else if (middle > x / middle) {
                right = middle - 1;
            } else {
                return middle;
            }
        }
        return right;
    }
};
// @lc code=end
