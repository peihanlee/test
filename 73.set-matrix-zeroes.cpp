/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.16%)
 * Likes:    1719
 * Dislikes: 282
 * Total Accepted:    287.2K
 * Total Submissions: 679K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m=matrix.size();
      int n=m?matrix[0].size():0;
      vector<int> r(m,0);
      vector<int> c(n,0);

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(!matrix[i][j]){
            r[i]=1;
            c[j]=1;
          }
        }
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(r[i] || c[j]){
            matrix[i][j]=0;
          }
        }
      }
        
    }
};
// @lc code=end
