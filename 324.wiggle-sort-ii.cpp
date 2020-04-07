/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (29.27%)
 * Likes:    899
 * Dislikes: 483
 * Total Accepted:    76.2K
 * Total Submissions: 260K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1, 5, 1, 1, 6, 4]
 * Output: One possible answer is [1, 4, 1, 5, 1, 6].
 * 
 * Example: 2:
 * 
 * 
 * Input: nums = [1, 3, 2, 2, 3, 1]
 * Output: One possible answer is [2, 3, 1, 3, 1, 2].
 * 
 * Note:
 * You may assume all input has valid answer.
 * 
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      vector<int> sorted(nums);
      int n=nums.size();
      if(n>0){
        sort(sorted.begin(), sorted.end());

        for(int i=0; i<n;i++){
          if(i&1){
            nums[i]=sorted[n-1-(i/2)];
          }else{
            nums[i]=sorted[(n-1)/2-(i/2)];
          }
        }
      }
    }
};
// @lc code=end
