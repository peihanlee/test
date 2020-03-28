/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.17%)
 * Likes:    4326
 * Dislikes: 202
 * Total Accepted:    889.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start
#include <stack>
class Solution {
public:
    bool isValid(string s) {
      int i;
      stack<char> st;
      for(i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
          st.push(s[i]);
        }else if(s[i]==')' && st.size()>0 && st.top()=='('){
          st.pop();
        }else if(s[i]==']' && st.size()>0 && st.top()=='['){
          st.pop();
        }else if(s[i]=='}' && st.size()>0 && st.top()=='{'){
          st.pop();
        }else{
          return false;
        }
      }
      if(st.size()==0)
        return true;
      else
        return false;     
    }
};
// @lc code=end
