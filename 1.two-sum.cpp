/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.11%)
 * Likes:    13785
 * Dislikes: 505
 * Total Accepted:    2.6M
 * Total Submissions: 5.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> save_data;

      for(int i=0;i<nums.size();i++){
        if(save_data.find(target-nums[i]) != save_data.end()){
          return {save_data[target-nums[i]],i};
        }
        save_data[nums[i]]=i;
      }
      return {};

        
    }
};
// @lc code=end
