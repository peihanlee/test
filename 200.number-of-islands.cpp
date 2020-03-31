/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (45.06%)
 * Likes:    4401
 * Dislikes: 160
 * Total Accepted:    580K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class Solution {
public:
    void removeMark(vector<vector<char>>& grid, int m, int n, int i, int j){
      if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
        return;
      }

      grid[i][j]='0';
      removeMark(grid,m,n,i-1,j);
      removeMark(grid,m,n,i+1,j);
      removeMark(grid,m,n,i,j-1);
      removeMark(grid,m,n,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
      int m=grid.size(), n=m?grid[0].size():0;
      int i,j;
      int totalIslands=0;

      for(i=0;i<m;i++){
        for(j=0;j<n;j++){
          if(grid[i][j]=='1'){
            totalIslands++;
            removeMark(grid,m,n,i,j);
          }
        }
      }        
      return totalIslands;
    }
};
// @lc code=end
