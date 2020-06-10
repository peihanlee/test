/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (36.17%)
 * Likes:    2283
 * Dislikes: 61
 * Total Accepted:    160.1K
 * Total Submissions: 440.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int m=matrix.size();
      int n=m?matrix[0].size():0;
      int maxRect=0;
      vector<int> height(n+1,0);

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(matrix[i][j]=='0'){
            height[j]=0;
          }else{
            height[j]++;
          }
        }

        stack<int> s;
        for(int k=0;k<height.size();k++){
          if(s.empty() || s.top()<=height[k]){
            s.push(height[k]);
          }else{
            int index=1;
            while(!s.empty() && s.top()>height[k]){
              maxRect = max(maxRect, s.top()*index);
              index++;
              s.pop();
            }
            //cout<<"maxRect:"<<maxRect;
            for(int x=0;x<index;x++){
              s.push(height[k]);
            }
          }
          //cout<<"["<<height[k]<<"] ";
        }
        //cout<<"\n";
      }
      return maxRect;
    }
};
// @lc code=end
