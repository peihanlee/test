/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (36.90%)
 * Likes:    1897
 * Dislikes: 97
 * Total Accepted:    240.2K
 * Total Submissions: 648.4K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int left = 0;
      int min_gap=INT_MAX;
      int sum=0;
      int n=nums.size();
      if(!n){
        return 0;
      }

      for(int i=0;i<n;i++){
        sum += nums[i];
        while(sum>=s && left<=i){
          min_gap = min(min_gap,i-left+1);
          sum -= nums[left];
          left++;
        }
      }
      if(min_gap==INT_MAX){
        return 0;
      } 
      return min_gap;
    }
};
// @lc code=end
