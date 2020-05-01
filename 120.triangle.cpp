/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (42.58%)
 * Likes:    1685
 * Dislikes: 204
 * Total Accepted:    230K
 * Total Submissions: 537.8K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int level=triangle.size();
      if(level==0){
        return 0;
      }
      for(int i=level-2;i>=0;i--){
        for(int j=0;j<=i;j++){
          triangle[i][j]=min(triangle[i][j]+triangle[i+1][j], triangle[i][j]+triangle[i+1][j+1]);
        }
      }
      return triangle[0][0];
    }
};
// @lc code=end
