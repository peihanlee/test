/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (50.47%)
 * Likes:    1167
 * Dislikes: 95
 * Total Accepted:    348.6K
 * Total Submissions: 687.2K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> result;
      vector<int> list;

      for(int i=0; i<numRows;i++){
        list.push_back(1);
        for(int j=i-1;j>0;j--){
          list[j]=list[j]+list[j-1];
        }
        result.push_back(list);
      }
      return result;        
    }
};
// @lc code=end
