/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    const vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    vector<string> dfs(int pos, string& digits, string& combination) {
        if (pos == digits.size()) {
            res.emplace_back(combination);
            return res;
        }
        int num = digits[pos] - '2';
        string s = map[num];
        for (char& c : s) {
            combination.push_back(c);
            dfs(pos + 1, digits, combination);
            combination.pop_back();
        }
        return res;
    }
    
    vector<string> letterCombinations(string digits) {
        // (1) backtracking time:O(3^m * 4^n) space:O(mn) where m is the number of digits corresponding to the 3 letters in the input, n is the number of digits corresponding to 4 letters in the input.
        if (digits.size() == 0) {
            return res;
        }
        string combination;
        return dfs(0, digits, combination);
    }
};
// @lc code=end

