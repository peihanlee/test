/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (35.65%)
 * Likes:    1210
 * Dislikes: 117
 * Total Accepted:    145.6K
 * Total Submissions: 408.2K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * Example 1:
 * 
 * 
 * Input: "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * 
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
      int sum=0;
      long value=0;
      vector<int> signs(2,1);

      for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
          value=0;
          while(s[i]>='0' && s[i]<='9' && i<s.size()){
            value = value*10 + (s[i]-'0');
            i++;
          }
          sum += signs.back()*value;
          signs.pop_back();
          i--;
        }else if(s[i]==')'){
          signs.pop_back();
        }else if(s[i]!=' '){
          signs.push_back(signs.back()*(s[i]=='-'?-1:1));
        }
        printf("sum=%d, i=%d\n",sum,i);
      }
      return sum;
    }
};
// @lc code=end
