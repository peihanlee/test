/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (35.54%)
 * Likes:    2346
 * Dislikes: 60
 * Total Accepted:    198.4K
 * Total Submissions: 556.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int max_area=0;
      if(!matrix.size() || !matrix[0].size()) return max_area;
      int m=matrix.size();
      int n=matrix[0].size();
      int tmp;

      vector<vector<int>> dp(m+1,vector<int>(n+1,0));

      for(int i=0;i<m ;i++){
        for(int j=0;j<n;j++){
          if(matrix[i][j]=='1'){
            tmp = min(dp[i+1][j],dp[i][j+1]);
            dp[i+1][j+1]=min(dp[i][j],tmp)+1;
            max_area=max(max_area,dp[i+1][j+1]);
          }
        }
      }
      return max_area*max_area;
    }
};
// @lc code=end
