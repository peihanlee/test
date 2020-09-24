/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (55.74%)
 * Likes:    628
 * Dislikes: 991
 * Total Accepted:    275.4K
 * Total Submissions: 493.1K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
      if(!num)
        return num;

      int tmp = num%9;
      
      return tmp?tmp:9;
    }
};
// @lc code=end
