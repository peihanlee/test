/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (33.67%)
 * Likes:    3046
 * Dislikes: 77
 * Total Accepted:    235.2K
 * Total Submissions: 695.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n=heights.size();
      int res = 0;
      stack<int> s;
      if(!n){
        return res;
      }
      n++;
      heights.push_back(0);
      for(int i=0;i<n;i++){
        int index=1;
        if(s.empty() || s.top()<=heights[i]){
          s.push(heights[i]);
        }else{
          while(!s.empty() && s.top()>heights[i]){
            res=max(res,s.top()*index);
            s.pop();
            index++;
          }
          for(int j=0;j<index;j++){
            s.push(heights[i]);
          }
        }
      }
      return res;
    }
};
// @lc code=end
