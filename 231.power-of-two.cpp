/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (42.87%)
 * Likes:    642
 * Dislikes: 163
 * Total Accepted:    278K
 * Total Submissions: 648.3K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {

      if(n>0){
        if(n==1)
          return true;
        
        while(n>1)
        {
          if(n%2==1){
            return false;
          }else{
            n=n/2;
          }
        }
        return true;
      } else {
        return false;
      }
    }
};
// @lc code=end
