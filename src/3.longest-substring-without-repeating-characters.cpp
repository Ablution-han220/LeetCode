/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // // sliding window using left for loop
        // unordered_map<int, int> map;
        // int j = -1;
        // int res = 0;
        // for(int i = 0; i < s.size(); i++){
        //     if(i != 0){
        //         map.erase(s[i - 1]);
        //     }
        //     while(j + 1 < s.size() && map.find(s[j + 1]) == map.end()){
        //         map[s[j + 1]] = 1;
        //         j++;
        //     }
        //     res = max((j-i+1), res);
        // }
        // return res;
        
        // sliding window using right for loop
        unordered_set<char> set;
        int left = 0;
        int res = 0;
        for(int j = 0; j < s.size(); j++){
            while(set.find(s[j]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[j]);
            res = max((j-left+1),res);
        }
        return res;
    }
};
// @lc code=end

