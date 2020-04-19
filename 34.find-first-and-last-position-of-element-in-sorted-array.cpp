/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.24%)
 * Likes:    2862
 * Dislikes: 128
 * Total Accepted:    449.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
public:

    int low_bound(vector<int>& nums,int target){
      int retult = 0;
      int l=0,r=nums.size()-1;
      int mid=0;

      while(l<=r){
        mid = (l+r)/2;
        if(nums[mid]<target){
          l=mid+1;
        }else{
          r=mid-1;
        }
      }
      return l;  
    } 

    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> result={-1,-1};
      if(nums.size()==0){
        return result;
      }
      int index1 = low_bound(nums, target);
      int index2 = low_bound(nums, target+1)-1;

      if(index1< nums.size() && nums[index1]==target){
        return {index1,index2};
      }else{
        return {-1,-1};
      }
    }
};
// @lc code=end
