/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // two pointers
        // string res;
        // for(int i = 0;i < s.size();i++){
        //     if(isalnum(s[i])){
        //         res += tolower(s[i]);
        //     }
        //     // if((s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <='9')){
        //     //     res += s[i];
        //     // }
        // }
        
        // two pointers:method 1
        // int left = 0;
        // int right = res.size() - 1;
        // while(left<right){
        //     if(res[left] != res[right]){
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        // return true;
        
        // two pointers:method 2
        int left = 0;
        int right = s.size() - 1;
        while(left<right){
            // pointer keeps moving until reaches the first letter or number
            while(left<right && !isalnum(s[left])){
                left++;
            }
            while(left<right && !isalnum(s[right])){
                right--;
            }
            if(left<right){
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
        
        
        
        // stack
        // stack<char> st;
        // for(int i = 0;i < s.size();i++){
        //     if(isalnum(s[i])){
        //         st.push(tolower(s[i]));
        //     }
        // }
        // for(int i = 0;i < s.size();i++){
        //     if(isalnum(s[i])){
        //         char c = st.top();
        //         if (c != tolower(s[i])){
        //             return false;
        //         }
        //         st.pop();
        //     }
        // }
        // return true;        
    }
};
// @lc code=end

