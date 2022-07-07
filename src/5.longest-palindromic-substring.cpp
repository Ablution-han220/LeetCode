/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
//         // dp
//         int n = s.size();
//         if(n < 2){
//             return s;
//         }
//         int maxLen = 1;
//         int begin = 0;
//         vector<vector<int>> dp(n,vector<int>(n));
//         for(int i = 0; i<n; i++){
//             dp[i][i] = true;
//         }
//         // length > 2
//         for(int L = 2; L <= n; L++){
//             for(int i = 0; i < n; i++){
//                 // right border j - i + 1 = L
//                 int j = L + i - 1;
//                 if(j >= n){
//                     break;
//                 }
                
//                 if(s[i] != s[j]){
//                     dp[i][j] = false;
//                 }else{
//                     // s[i] = s[j] 
//                     // if s[i..j] <= 3 must be palindromic
//                     if(j - i + 1 <= 3){
//                         dp[i][j] = true;
//                     }else{
//                         dp[i][j] = dp[i+1][j-1]; 
//                     }
//                 }
//                 // update maxLen and begin
//                 if(dp[i][j] && (j - i + 1 > maxLen)){
//                     maxLen = j - i + 1;
//                     begin = i;
//                 }
//             }
//         }
//         return s.substr(begin,maxLen);
//     }
        
        // center extension
        int begin = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            int len1 = extendAroundCenter(s,i,i);
            int len2 = extendAroundCenter(s,i,i+1);
            int len = max(len1,len2);
            if(len > end - begin + 1){
                begin = i - (len -1) /2;
                end = i + len/2;
            }
        }
        return s.substr(begin,end - begin + 1);
    }    
    
    int extendAroundCenter(string s,int left,int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        // return the length of center right - left + 1 - 2 = right - left - 1
        return right - left - 1;
    }
        
};
// @lc code=end

