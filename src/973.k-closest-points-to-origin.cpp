/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     // (1) sort o(nlogn)
    //     sort(points.begin(),points.end(),[](const vector<int>&a, const vector<int>&b){
    //         return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    //     });
    //     return {points.begin(),points.begin() + k};
    // }
        // (2) max-heap o(nlogk)
        
        // Using lambda to compare elements. lambda
        // auto cmp = [](const pair<int,int>&a,pair<int,int>&b){
        //     return a.second < b.second;
        // };
        // priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> max_heap(cmp);
        
        // Using custom function object
        struct cmp{
            bool operator()(const pair<int,int>&a,pair<int,int>&b){
                return a.second < b.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> max_heap;
        for (int i = 0; i < k; ++i) {
            max_heap.emplace(i,points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        }
        
        for (int i = k; i < points.size(); ++i) {
            int cur_dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            int top = max_heap.top().second;
            if (cur_dist < top) {
                max_heap.pop();
                max_heap.emplace(i,cur_dist);
            }
        }
        
        vector<vector<int>> res;
        while (!max_heap.empty()) {
            res.emplace_back(points[max_heap.top().first]);
            max_heap.pop();
        }
        return res;
    }
};
// @lc code=end

