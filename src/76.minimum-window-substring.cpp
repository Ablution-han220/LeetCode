/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window,target;
        for(char c:t){
            target[c]++;
        }
        string res;
        int left = 0, right = 0;
        // cnt is a variable which can decide whether window contains every character in t
        int cnt = 0;
        for(right; right < s.size();right++){
            window[s[right]]++;
            if(window[s[right]] <= target[s[right]]){
                cnt++;
            }
            while(window[s[left]] > target[s[left]]){
                window[s[left]]--;
                left++;
            }
            if(cnt == t.size()){
                if(res.empty() || right-left+1 < res.size()){
                    res = s.substr(left,right-left+1);
                }
            }
            
        }
        return res;
    }
};
// @lc code=end

