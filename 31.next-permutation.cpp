/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.87%)
 * Likes:    2833
 * Dislikes: 978
 * Total Accepted:    328.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int i=0;
      int j=0;
      if(nums.size()<=1)
        return;
      for(i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1])
          break;       
      }
      sort(nums.begin()+i+1,nums.end());
      if(i>=0){
        for(j=i+1;j<nums.size();j++){
          if(nums[i]<nums[j])
            break;
        }
        swap(nums[i],nums[j]);
      }
    }
};
// @lc code=end
