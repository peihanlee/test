/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.46%)
 * Likes:    560
 * Dislikes: 2216
 * Total Accepted:    349.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {  
public:
    int lengthOfLastWord(string s) {
      int start=-1;
      int end=-1;
      int length=s.length();
      int i=length-1;

      while(i>=0){
        if(end==-1 && s[i]!=' '){
          end = i;
        }else if(end!=-1 && start==-1 && s[i]==' '){
          start = i;
          break;
        }
        i--;
      }
      return end-start;
    }
};
// @lc code=end
