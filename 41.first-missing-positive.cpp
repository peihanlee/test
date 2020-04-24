/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.94%)
 * Likes:    2894
 * Dislikes: 740
 * Total Accepted:    301.4K
 * Total Submissions: 970.7K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n=nums.size();
      int i = 0;

      for(i=0;i<n;i++){
        while(nums[i]!=i+1 && nums[i]>0 &&  nums[i]-1<n && nums[i]!=nums[nums[i]-1]){
          swap(nums[i],nums[nums[i]-1]);
        }
      }

      for(i=0;i<n;i++){
        if(nums[i]!=i+1){
          return i+1;
        }
      }
      return i+1;
    }
};
// @lc code=end
