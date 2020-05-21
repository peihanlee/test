/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (37.18%)
 * Likes:    611
 * Dislikes: 82
 * Total Accepted:    97.9K
 * Total Submissions: 263K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * Example 1:
 * 
 * 
 * Input: [5,7]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1]
 * Output: 0
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      unsigned int mask = INT_MAX;

      cout<<"mask&m:"<<to_string(mask&m)<<"\n";
      cout<<"mask&n:"<<to_string(mask&n)<<"\n";
      //while((unsigned int)(mask&m) != (unsigned int)(mask&n)){
      while((mask&m) != (mask&n)){
        mask = mask<<1;
        cout<<"mask:"<<mask<<"\n";
      }

      return mask&m;        
    }
};
// @lc code=end
