/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.72%)
 * Likes:    1771
 * Dislikes: 124
 * Total Accepted:    440.2K
 * Total Submissions: 962.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int result=0;
      int sum=0;
      int left=0,right=0;
      int minDiff=INT_MAX;

      if(nums.size()<3){
        return sum;
      }

      sort(nums.begin(),nums.end());
      result=nums[0]+nums[1]+nums[2];
      minDiff=abs(result-target);

      for(int i=0;i<nums.size()-2;i++){
        left=i+1;
        right=nums.size()-1;

        while(left<right){
          sum = nums[i]+nums[left]+nums[right];
          if(sum==target){
            return sum;
          }else if(abs(sum-target)<minDiff){
            minDiff = abs(sum-target);
            result = sum;
          }
          if(sum>target){
            right--;
          }else{
            left++;
          }
        }
      }
      return result;
    }
};
// @lc code=end
