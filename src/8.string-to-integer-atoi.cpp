/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
// class Solution {
// public:
//     int myAtoi(string s) {
//         int res = 0;
//         bool flag = true;
//         bool op_flag = true;
//         bool has_num = false;
//         for(int i = 0; i < s.size();i++){
//             if(s[i] == ' ' && !has_num){
//                 continue;
//             }else if(s[i] == '-' && op_flag && !has_num){
//                 if(!isdigit(s[i+1])){
//                     return 0;
//                 }
//                 flag = false;
//                 op_flag = false;
//                 continue;
//             }else if(s[i] == '+' && op_flag && !has_num){
//                 if(!isdigit(s[i+1])){
//                     return 0;
//                 }
//                 op_flag = false;
//                 continue;
//             }else if(isdigit(s[i])){
//                 has_num = true;
//                 int num = s[i] - '0';
//                 if(res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)){
//                     return flag == true? INT_MAX:INT_MIN;
//                 }
//                 res = res * 10 + num;
//             }else{
//                 break;
//             }
//         }
//         return flag == true? res:-res;
//     }
// };

// deterministic finite automaton
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
// @lc code=end

