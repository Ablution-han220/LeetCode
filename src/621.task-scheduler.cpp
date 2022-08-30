/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // (1) greedy time:O(tasks) space:O(1)
    //     vector<int> frq(26);
    //     for (char& t: tasks) {
    //         frq[t - 'A'] += 1;
    //     }
    //     sort(frq.begin(),frq.end(),greater<int>());
    //     int f_max = frq[0];
    //     int idle_time = (f_max - 1) * n;
    //     for (int i = 1; i < frq.size() && idle_time >= 0; ++i) {
    //         idle_time -= min(frq[i], f_max - 1);
    //     }
    //     idle_time = max(0, idle_time);
    //     return idle_time + tasks.size();
    // }
        
        // (2) math
        vector<int> frq(26);
        for (char& t: tasks) {
            frq[t - 'A'] += 1;
        }
        
        int f_max = 0;
        for (int f: frq) {
            f_max = max(f_max, f);
        }
        int n_max = 0;
        for (int f: frq) {
            if (f == f_max) {
                ++n_max;
            }
        }
        int len = tasks.size();
        return max(len, (f_max - 1) * (n + 1) + n_max);
    }
};
// @lc code=end

