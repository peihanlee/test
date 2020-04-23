/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (42.61%)
 * Likes:    1516
 * Dislikes: 258
 * Total Accepted:    409.7K
 * Total Submissions: 955.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
      string result="";
      int carry=0;
      int add;
      int a_size=a.size();
      int b_size=b.size();

      int n=max(a_size,b_size);
      int i=0;
      int an=0;
      int bn=0;
      

      while(i<n){
        if(i<a_size){
          an=a[a_size-1-i]-'0';
        }else{
          an=0;
        }
        if(i<b_size){
          bn=b[b_size-1-i]-'0';
        }else{
          bn=0;
        }
        add = an+bn+carry;
        result = to_string(add%2)+result;
        carry = add/2;

        i++;
      }

      if(carry>0){
        result="1"+result;
      }
      return result;
    }
};
// @lc code=end
