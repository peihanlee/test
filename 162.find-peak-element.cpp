/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (42.60%)
 * Likes:    1359
 * Dislikes: 1810
 * Total Accepted:    317.9K
 * Total Submissions: 744.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int i;
      int res = 0;
      int foundLeft = 0;
      for(i=0;i<nums.size()-1;i++){
        if(foundLeft == 0){
          if(nums[i]<nums[i+1]){
            res=foundLeft=i+1;
          }
        } else {
          if(nums[i]<=nums[i+1]){
            res=i+1;
          } else {
            res = i;
            break;
          }
        }
      }
      return res;
    }
};
// @lc code=end
