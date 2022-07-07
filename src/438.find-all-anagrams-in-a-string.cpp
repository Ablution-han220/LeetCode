/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       unordered_map<char,int> map,window;
        for(char c:p){
             map[c]++;
        }
        int window_size = p.size();
        int left = 0,right = 0;
        // cnt is a variable which can decide whether window contains every character in p;
        int cnt = 0;
        vector<int>res; 
        // for(int right = 0; right < s.size(); right++){
        while(right < s.size()) {
            char c = s[right];
            right++;
            if (map.count(c)) {
                window[c]++;
                if (window[c] == map[c]) {
                    cnt++;
                }
            }
            while(right - left >= window_size){
                if (cnt == map.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (map.count(d)) {
                    if (window[d] == map[d]) {
                        cnt--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

