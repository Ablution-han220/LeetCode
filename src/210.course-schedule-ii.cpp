/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    stack<int> s;
    bool valid = true;
    void dfs(int n, vector<vector<int>>& edges, vector<int>& visit) {
        visit[n] = 1;
        for (int course:edges[n]) {
            if (visit[course] == 0) {
                dfs(course,edges,visit);
                if (!valid) {
                    return;
                }
            } else if (visit[course] == 1) {
                valid = false;
                return;
            }
        }
        visit[n] = 2;
        s.push(n);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // (1) bfs time:O(n+m) space:O(n+m)
//         vector<vector<int>> edges(numCourses);
//         vector<int> indegree(numCourses);
        
//         for (auto info:prerequisites) {
//             edges[info[1]].emplace_back(info[0]);
//             ++indegree[info[0]];
//         }
//         queue<int> q;
//         for (int i = 0; i < numCourses; ++i) {
//             if (indegree[i] == 0) {
//                 q.emplace(i);
//             }
//         }
//         vector<int>take;
//         while (!q.empty()) { 
//             int pre_course = q.front();
//             take.emplace_back(pre_course);
//             q.pop();
//             for(int course:edges[pre_course]) {
//                 --indegree[course];
//                 if (indegree[course] == 0) {
//                     q.emplace(course);
//                 }
//             }
//         }
//         if (take.size() == numCourses) {
//             return take;
//         }
//         return {};
//     }
        // (2) dfs time:O(n+m) space:O(n+m)
        vector<vector<int>> edges(numCourses);
        // 0 = not_visited, 1 = visited, 2 = checked
        vector<int> visit(numCourses,0);
        for (auto info:prerequisites) {
            edges[info[1]].emplace_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (visit[i] == 0) {
                dfs(i,edges,visit);
            }
        }
        if (!valid) {
            return {};
        }
        vector<int> res;
        while (!s.empty()) {
            res.emplace_back(s.top());
            s.pop();
        }
        return res;
    }
};
// @lc code=end

