/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    // time:O(n) space:O(n)
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
    // int calculate(string s) {
    //     int i = 0;
    //     return helper(s, i);
        
    // }
    // int helper(string s, int &i) {
    //     stack<int> st;
    //     char sign = '+';
    //     int num  = 0;
    //     for (i; i < s.size(); ++i) {
    //         if (s[i] >= '0' && s[i] <= '9') {
    //             num = 10 * num + (s[i] - '0');
    //         }
    //         if (s[i] == '(') {
    //             num = helper(s,++i);
    //             // ++i;
    //         }
    //         if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
    //             switch(sign) {
    //                 case '+':
    //                     st.push(num);
    //                     break;
    //                 case '-':
    //                     st.push(-num);
    //                     break;
    //             }
    //             sign = s[i];
    //             num = 0;
    //         }
    //         if (s[i] == ')') {
    //             ++i;
    //             break;
    //         }
    //     }
    //     int res = 0;
    //     while (!st.empty()) {
    //         res += st.top();
    //         st.pop();
    //     }
    //     return res;
    // }
};
// @lc code=end

