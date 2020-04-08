/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (44.82%)
 * Likes:    2251
 * Dislikes: 170
 * Total Accepted:    253.2K
 * Total Submissions: 564.2K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
class Solution {
public:
    int DFS(int n, unordered_map<int,int> &dp){
      int res=INT_MAX;
      if(n>0){
        if(dp.count(n)){
          res = dp[n];
        }else{
          for(int i=1; i*i<=n ; i++){
            res = min(res, DFS(n-(i*i),dp)+1);
          }
          dp[n]=res;
        }
        return res;
      }else{
        return 0;
      }
    }
    int numSquares(int n) {
      static unordered_map<int, int> dp;

      return DFS(n,dp);        
    }
};
// @lc code=end
