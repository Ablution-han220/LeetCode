/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mage;
        for (char c:magazine) {
            ++mage[c];
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (mage.find(ransomNote[i]) != mage.end()) {
                if (mage[ransomNote[i]] == 0) {
                    return false;
                }
                --mage[ransomNote[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

