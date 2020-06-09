/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (35.86%)
 * Likes:    1514
 * Dislikes: 98
 * Total Accepted:    159K
 * Total Submissions: 437.9K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkPalidrome(string s, int i, int j, bool del){
      while(i<j){
        if(s[i]!=s[j] && del==false){
          return checkPalidrome(s,i+1,j,true) || checkPalidrome(s,i,j-1,true);
        }else if(s[i]!=s[j]){
          return false;
        }
        i++; j--;
      }
      return true;
    }
    bool validPalindrome(string s) {
      return checkPalidrome(s,0,s.size()-1,false);        
    }
};
// @lc code=end
