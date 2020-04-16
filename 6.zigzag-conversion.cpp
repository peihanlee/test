/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (35.00%)
 * Likes:    1493
 * Dislikes: 4261
 * Total Accepted:    428.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
      string res={};
      int gap=2*numRows-2;
      int second_pos=0;

      if(numRows == 1) return s;

      for(int i=0;i<numRows;i++){
        for(int j=i;j<s.size();j+=gap){
          res.push_back(s[j]);
          second_pos=j-i+gap-i;
          if(i>=1 && i<numRows-1 && second_pos<s.size()){
            res.push_back(s[second_pos]);
          }
        }

      }
      return res;
        
    }
};
// @lc code=end
