/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.91%)
 * Likes:    1869
 * Dislikes: 514
 * Total Accepted:    325.8K
 * Total Submissions: 990.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int row=0;
      int col=0;
      int position = 0;
      int u,d,l,r;
      int n,m;

      n=matrix.size();
      if(n)
        m=matrix[0].size();

      vector<int> ret(n*m);

      u=0;
      d=n-1;
      l=0;
      r=m-1;

      while(u<=d && l<=r)
      {
        for(row=l;row<=r;row++){
          ret[position++]=matrix[u][row];
          cout<<ret[position-1]<<"_";
        }
        u++;
        if(u>d){
          break;
        }

        for(col=u;col<=d;col++){
          ret[position++]=matrix[col][r];
          cout<<ret[position-1]<<"_";
        }

        r--;
        if(r<l){
          break;
        }

        for(row=r;row>=l;row--){
          ret[position++]=matrix[d][row];
          cout<<ret[position-1]<<"_";
        }

        d--;
        if(d<u){
          break;
        }

        for(col=d;col>=u;col--){
          ret[position++]=matrix[col][l];
          cout<<ret[position-1]<<"_";
        }

        l++;
        if(l>r){
          break;
        }
      }

      return ret;
    }
};
// @lc code=end
