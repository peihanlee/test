/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.48%)
 * Likes:    2987
 * Dislikes: 128
 * Total Accepted:    261.3K
 * Total Submissions: 947.4K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
      int res=0;
      int start=0;
      stack<int> st;

      for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(i);
        else{
          if(st.empty()) start=i+1;
          else{
            st.pop();
            res = st.empty()? max(res,i-start+1):max(res,i-st.top());
          }
        }
      }

      return res;
    }
};
// @lc code=end
