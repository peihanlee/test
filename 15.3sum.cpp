/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.83%)
 * Likes:    6030
 * Dislikes: 734
 * Total Accepted:    826.3K
 * Total Submissions: 3.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int target = 0;
      int left=0,right=0;
      vector<vector<int>> result={};
      if(nums.size()<3){
        return result;
      }

      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size()-2;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        target=-nums[i];
        left=i+1;
        right=nums.size()-1;
        while(left<right){
          if(nums[left]+nums[right]<target){
            left++;
          }else if(nums[left]+nums[right]>target){
            right--;
          }else{
            result.push_back({nums[i],nums[left],nums[right]});
            left++;
            right--;
            while(left<right && nums[left]==nums[left-1]) left++;
            while(left<right && nums[right]==nums[right+1]) right--;
          }
        }
      }

      return result;
             
    }
};
// @lc code=end
