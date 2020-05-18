/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (44.28%)
 * Likes:    1741
 * Dislikes: 214
 * Total Accepted:    396K
 * Total Submissions: 893K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getMin(vector<int>& nums, int l, int r){
      if(nums[l]<=nums[r]) return nums[l];
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
