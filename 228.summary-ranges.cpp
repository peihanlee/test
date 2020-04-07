/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (38.41%)
 * Likes:    545
 * Dislikes: 481
 * Total Accepted:    157.1K
 * Total Submissions: 408.8K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> res;
      string tmpStr="";
      int n=nums.size();
      int i=0;
      int start_i=0;

      if(n==0){
        return res;
      }

      for(i=0;i<n-1;i++){
        if(tmpStr.empty())
        {
          tmpStr.append(to_string(nums[i]));
          start_i=i;
        }
        if(nums[i]+1!=nums[i+1]){
          if(start_i!=i){
            tmpStr.append("->");
            tmpStr.append(to_string(nums[i]));            
          }
          res.push_back(tmpStr);
          tmpStr="";          
        }
      }

      //i==n-1
      if(!tmpStr.empty()){
        if(start_i!=i){
          tmpStr.append("->");
          tmpStr.append(to_string(nums[i]));            
        }
      }else{
        tmpStr.append(to_string(nums[i]));            
      }
      res.push_back(tmpStr);
      return res;
    }
};
// @lc code=end
