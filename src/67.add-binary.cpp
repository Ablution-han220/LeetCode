/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
    //(1) Bit-by-Bit Computation time:O(max(N,M)) space:O(max(N,M))
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int n = max(a.size(),b.size());
        int carry = 0;
        string res;
        for (int i = 0; i < n; ++i) {
            if (i < a.size()) {
                carry += a[i] - '0';
            }
            if (i < b.size()) {
                carry += b[i] - '0';
            }
            int cur_carry = (carry % 2) ? '1' : '0';
            res.push_back(cur_carry);
            carry = carry / 2;
        }
        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
        // (2) Bit Manipulation
//         bitset<128> x(a);
//         bitset<128> y(b);
        
//         while (y.any()) {
//             bitset<128> answer = x ^ y;
//             bitset<128> carry = (x & y) << 1;
//             x = answer;
//             y = carry;
//         }
        
//         string s = x.to_string();
//         int i = 0;
//         while(s[i] == '0') i++;
//         s = s.substr(i);
//         return s=="" ? "0":s;
//     }
};
// @lc code=end

