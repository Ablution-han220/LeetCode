/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // // (1) sort
        // if (s.length() != t.length()){
        //     return false;
        // }
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s == t;
        
        // (2) hash_map
        if (s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> map;
        for(int i = 0; i<s.length(); i++){
            map[s[i]]++;
            map[t[i]]--;
        }
        // for(int i = 0; i < map.size(); i++){
        //     if(map[i] != 0){
        //         return false;
        //     }
        // }
        for(unordered_map<char,int>::iterator it=map.begin();it!=map.end();it++){
            if(it->second!= 0)
                return false;
        }
        return true;
        
    }
};
// @lc code=end

