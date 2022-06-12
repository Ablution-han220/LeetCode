/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // // o(nlogn) use sort
        // intervals.push_back(newInterval);
        // vector<vector<int>> newintervals;
        // sort(intervals.begin(),intervals.end());
        // int left = intervals[0][0];
        // int right = intervals[0][1];
        // for(int i = 0; i < intervals.size(); i++){
        //     if(i < intervals.size() - 1){
        //         int next_left = intervals[i+1][0];
        //         int next_right = intervals[i+1][1];
        //         if(right < next_left){
        //             newintervals.push_back({left,right});
        //             left = next_left;
        //             right = next_right;
        //             continue;
        //         }else{
        //             left = min(left,next_left);
        //             right = max(right,next_right);
        //             continue;
        //         }
        //     }else{
        //         newintervals.push_back({left,right});
        //     }       
        // }
        // return newintervals;
        
        //  o(n)
        vector<vector<int>> resultintervals;
        int left = newInterval[0];
        int right = newInterval[1];
        bool place = false;
        for(int i = 0; i < intervals.size(); i++){
            if(left > intervals[i][1]){
                resultintervals.push_back(intervals[i]);
            }else if(right < intervals[i][0]){
                if(!place){
                    resultintervals.push_back({left,right});
                    place = true;
                }
                resultintervals.push_back(intervals[i]);
            }else{
                left = min(left,intervals[i][0]);
                right = max(right,intervals[i][1]);
            }
        }
        if(!place){
            resultintervals.push_back({left,right});
        }
        return resultintervals;
    }
};
// @lc code=end

