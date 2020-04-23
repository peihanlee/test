/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (51.26%)
 * Likes:    2311
 * Dislikes: 50
 * Total Accepted:    328.1K
 * Total Submissions: 636.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m=grid.size(); 
      int n=grid[0].size();

      vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));

      for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
          if(dp[i-1][j]==INT_MAX && dp[i][j-1]==INT_MAX){
            dp[i][j]=grid[i-1][j-1];
          }else{
            dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
          }
        }
      }
      return dp[m][n];
    }
};
// @lc code=end
