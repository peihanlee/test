/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (40.30%)
 * Likes:    730
 * Dislikes: 197
 * Total Accepted:    165.2K
 * Total Submissions: 409.3K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getMin(vector<int>& nums, int l, int r){
      if(l==r) return nums[l];
      if(nums[l]<nums[r]) return nums[l];
      int mid=(l+r)/2;

      return min(getMin(nums,l,mid),getMin(nums,mid+1,r));
    }
    int findMin(vector<int>& nums) {
      int n=nums.size();
      if(n<1){
        return 0;        
      }

      return getMin(nums,0,n-1);
    }
};
// @lc code=end
