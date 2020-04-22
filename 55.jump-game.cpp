/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (33.32%)
 * Likes:    3257
 * Dislikes: 291
 * Total Accepted:    383.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int start=0;
      int end=0;
      int maxEnd=0;
      int n=nums.size();

      while(start<=end){
        for(int i=start;i<=end;i++){
          maxEnd=max(maxEnd,i+nums[i]);
          if(maxEnd>=n-1){
            return true;
          }
        }
        start=end+1;
        end=maxEnd;
      }
      return false;
    }
};
// @lc code=end
