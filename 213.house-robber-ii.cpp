/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (36.01%)
 * Likes:    1441
 * Dislikes: 45
 * Total Accepted:    157K
 * Total Submissions: 435.3K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
      int size=nums.size();
      if(!size) return 0;
      if(size==1) return nums[0];

      return max(robRange(nums,0,size-1),robRange(nums,1,size));
    }

    int robRange(vector<int>& nums, int left, int right){
      //if(right-left==1) return nums[left];
      int robMax=nums[left];
      int noRobMax=0;

      for(int i=left+1; i<right; i++){
        int pre_robMax=robMax;
        int pre_noRobMax=noRobMax;

        robMax = pre_noRobMax + nums[i];
        noRobMax = max(pre_robMax, pre_noRobMax);
      }

      return max(robMax, noRobMax);

    }
};
// @lc code=end
