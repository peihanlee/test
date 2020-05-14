/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (63.23%)
 * Likes:    4020
 * Dislikes: 150
 * Total Accepted:    784.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int res=0;
      for(int i=0;i<nums.size();i++){
        res = res ^ nums[i];
      }
      return res;        
    }
};
// @lc code=end
