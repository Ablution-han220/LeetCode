/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        // (1) using stack  time:O(n) space:O(n)
    //     stack<int> st;
    //     char sign = '+';
    //     int num  = 0;
    //     for (int i = 0; i < s.size(); ++i) {
    //         if (s[i] >= '0' && s[i] <= '9') {
    //             num = 10 * num + (s[i] - '0');
    //         }
    //         if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
    //             switch(sign) {
    //                 int pre;
    //                 case '+':
    //                     st.push(num);
    //                     break;
    //                 case '-':
    //                     st.push(-num);
    //                     break;
    //                 case '*':
    //                     pre = st.top();
    //                     st.pop();
    //                     st.push(pre * num);
    //                     break;
    //                 case '/':
    //                     pre = st.top();
    //                     st.pop();
    //                     st.push(pre / num);
    //                     break;
    //             }
    //             sign = s[i];
    //             num = 0;
    //         }
    //     }
    //     int res = 0;
    //     while (!st.empty()) {
    //         res += st.top();
    //         st.pop();
    //     }
    //     return res;
    // }
        // (2) without stack  time:O(n) space:O(1)
        char sign = '+';
        int num  = 0;
        int pre_num = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                switch(sign) {
                    case '+':
                        res += pre_num;
                        pre_num = num;
                        break;
                    case '-':
                        res += pre_num;
                        pre_num = -num;
                        break;
                    case '*':
                        pre_num = pre_num * num;
                        break;
                    case '/':
                        pre_num = pre_num / num;
                        break;
                }
                sign = s[i];
                num = 0;
            }
        }
        res += pre_num;
        return res;
    }
};
// @lc code=end

