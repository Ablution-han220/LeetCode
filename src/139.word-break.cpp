/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // (1) bfs time:O(n^3) space:O(n)
    //     unordered_set<string> word_set(wordDict.begin(), wordDict.end());
    //     queue<int> q;
    //     q.emplace(0);
    //     vector<bool> visit(s.size(), false);
    //     while (!q.empty()) {
    //         int start = q.front();
    //         q.pop();
    //         if (visit[start] == true) {
    //             continue;
    //         }
    //         for (int i = start + 1; i <= s.size(); ++i) {
    //             if (word_set.find(s.substr(start, i - start)) != word_set.end()) {
    //                 q.emplace(i);
    //                 if (i == s.size()) {
    //                     return true;
    //                 }
    //             }
    //         }
    //         visit[start] = true;
    //     }
    //     return false;
    // }
        
        // (2) dp
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp (s.size() + 1, false);
        dp[0] = true;
        
        // dp[i]=dp[j] && check(s[j..i−1])
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] == true && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

