/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int res = 0;
        for(char c:s){
            map[c]++;
        }
        for(unordered_map<char,int>::iterator it = map.begin(); it!= map.end();it++){
            int num = it->second;
            res = res + num / 2 * 2;
            // if(num % 2 == 1 && res % 2 == 0){
            //     res++;
            // }
        }
        if(res<s.size()){
            res++;
        }
        return res;
    }
};
// @lc code=end

