/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.65%)
 * Likes:    4054
 * Dislikes: 124
 * Total Accepted:    465.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      int rob_max=0;
      int notRob_max=0;
      if(n<1){
        return 0;
      }
      for(int i=0;i<n;i++){
        int preRob_max=rob_max;
        int preNotRob_max=notRob_max;
        rob_max = preNotRob_max+nums[i];
        notRob_max = max(preRob_max, preNotRob_max);
      }
      return max(rob_max,notRob_max);
    }
};
// @lc code=end
