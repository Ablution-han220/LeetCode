/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (isBadVersion(middle)) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }
};
// @lc code=end

