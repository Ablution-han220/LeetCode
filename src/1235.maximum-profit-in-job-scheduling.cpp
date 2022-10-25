/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * algorithms
 * Hard (50.99%)
 * Likes:    3870
 * Dislikes: 40
 * Total Accepted:    138.5K
 * Total Submissions: 271.1K
 * Testcase Example:  '[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]'
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 * 
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 * 
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * 
 * 
 * Example 2:
 * 
 * ⁠
 * 
 * 
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job. 
 * Profit obtained 150 = 20 + 70 + 60.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * 1 <= startTime[i] < endTime[i] <= 10^9
 * 1 <= profit[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int binarysearch(vector<vector<int>>& jobs, int right, int target) {
        int left = 0;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (jobs[mid][1] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2){return job1[1] < job2[1];});
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k = binarysearch(jobs, i - 1, jobs[i - 1][0]);
            // int k = upper_bound(jobs.begin(), jobs.end(), jobs[i - 1][0],[&](int st, const vector<int> &job){return st < job[1];}) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
// @lc code=end

