/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.52%)
 * Likes:    1936
 * Dislikes: 229
 * Total Accepted:    546.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchPosition(vector<int>& nums, int start, int end, int target){
      int result;
      if(start>end){
        return start;
      }else{
        int mid=(start+end)/2;
        if(nums[mid]>target){
          return searchPosition(nums, start, mid-1, target);
        }else if(nums[mid]<target){
          return searchPosition(nums, mid+1, end, target);
        }else{
          return mid;
        }
      }
    }

    int searchInsert(vector<int>& nums, int target) {
      int n = nums.size();
      
      if(n == 0){
        return 0;
      }else{
        return searchPosition(nums,0,n-1,target);
      }
    }
};
// @lc code=end
