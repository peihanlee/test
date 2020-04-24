/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (51.67%)
 * Likes:    824
 * Dislikes: 102
 * Total Accepted:    179.5K
 * Total Submissions: 345.5K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res(n,vector<int>(n));
      int left=0,top=0,right=n-1,down=n-1;
      int i;
      int j;
      int val=1;

      while(left<=right && top<=down){
        
        j=left;
        while(j<=right){
          res[top][j]=val++;
          j++;
        }
        top++;
        
        i=top; 
        while(i<=down){
          res[i][right]=val++;
          i++;
        }
        right--;

        j=right;
        while(j>=left){
         res[down][j]=val++;
         j--;
        }
        down--;
        
        i=down;
        while(i>=top){
          res[i][left]=val++;
          i--;
        }
        left++;

        //cout<<"end:"<<left<<","<<top<<","<<right<<","<<down<<"\n";
      }

      return res;
    }
};
// @lc code=end
