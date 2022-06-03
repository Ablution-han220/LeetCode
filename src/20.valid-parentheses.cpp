/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // simple stack
        // stack<char> st;
        // int length = s.size();
        // if(length % 2 == 1){
        //     return false;
        // }
        // for(int i = 0;i< length;i++){
        //     // left parentheses
        //     if(s[i] == '(' || s[i] == '[' || s[i] == '{'  ){
        //         st.push(s[i]);
        //     }
        //     else{
        //         if(st.empty()){
        //             return false;
        //         }
        //         else if(s[i] == ')' && st.top() != '('){
        //             return false;
        //         }
        //         else if(s[i] == ']' && st.top() != '['){
        //             return false;
        //         }
        //         else if(s[i] == '}' && st.top() != '{'){
        //             return false;
        //         }
        //         else{
        //             st.pop();
        //         }
        //     }
        // }
        // return st.empty();
        
        // stack + hashmap
        stack<char> st;
        unordered_map<char,char> p_map;
        p_map['('] = ')';
        p_map['['] = ']';
        p_map['{'] = '}';
        int length = s.size();
        if(length % 2 == 1){
            return false;
        }
        for(int i = 0;i< length;i++){
            // left parentheses
            if(p_map.count(s[i])){
                st.push(s[i]);
            }else{
                // right parenthese
                if(st.empty() || p_map[st.top()] != s[i]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

