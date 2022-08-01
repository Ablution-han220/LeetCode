/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    bool isOperator(string& tokens) {
        if (tokens == "+" || tokens == "-" || tokens == "*" || tokens == "/") {
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isOperator(tokens[i])) {
                int number2 = stk.top();
                stk.pop();
                int number1 = stk.top();
                stk.pop();
                int num = 0;
                switch (tokens[i][0]) {
                    case '+':
                        num = number1 + number2;
                        stk.push(num);
                        break;
                    case '-':
                        num = number1 - number2;
                        stk.push(num);
                        break; 
                    case '*':
                        num = number1 * number2;
                        stk.push(num);
                        break;
                    case '/':
                        num = number1 / number2;
                        stk.push(num);
                        break;
                }
            } else {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};
// @lc code=end

