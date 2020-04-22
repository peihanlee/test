/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (29.84%)
 * Likes:    2070
 * Dislikes: 118
 * Total Accepted:    234.8K
 * Total Submissions: 785K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
      int start=0;
      int end=0;
      int maxEnd=0;
      int n=nums.size();
      int step=0;

      while(end<n-1){
        step++;
        for(int i=start;i<=end;i++){
          maxEnd=max(maxEnd,i+nums[i]);
          if(maxEnd>=n-1){
            return step;
          }
        }
        start=end+1;
        end=maxEnd;
      }
      return step;
    }
};
// @lc code=end
