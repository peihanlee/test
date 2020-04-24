/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.83%)
 * Likes:    1537
 * Dislikes: 705
 * Total Accepted:    269.6K
 * Total Submissions: 817.6K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
      string result="";
      int n=num1.size()-1;
      int m=num2.size()-1;
      int carry=0;

      if((n==0 && num1[0]=='0') || (m==0 && num2[0]=='0')){
        return "0";
      }

      for(int i=0;i<(n+m+1);i++){
        for(int j=max(0,i-m);j<=min(i,n);j++){
          int a_n=num1[n-j]-'0';
          int b_n=num2[m-(i-j)]-'0';
          carry+=a_n*b_n;
          //cout<<"Total:"<<carry<<"\n";
        }
        result=to_string(carry%10)+result;
        carry /= 10;
        //cout<<"carry:"<<carry<<"\n";
      }
      if(carry){
        result=to_string(carry%10)+result;
      }
      return result;
    }
};
// @lc code=end
