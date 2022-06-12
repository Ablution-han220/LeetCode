/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
                vector<vector<int>> newintervals;
        sort(intervals.begin(),intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 0; i < intervals.size(); i++){
            if(i < intervals.size() - 1){
                int next_left = intervals[i+1][0];
                int next_right = intervals[i+1][1];
                if(right < next_left){
                    newintervals.push_back({left,right});
                    left = next_left;
                    right = next_right;
                    continue;
                }else{
                    left = min(left,next_left);
                    right = max(right,next_right);
                    continue;
                }
            }else{
                newintervals.push_back({left,right});
            }       
        }
        return newintervals;
    }
};
// @lc code=end

