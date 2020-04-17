/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (32.70%)
 * Likes:    1623
 * Dislikes: 303
 * Total Accepted:    307.9K
 * Total Submissions: 938.5K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> result={};
      int n=nums.size();
      int left=0,right=0;

      if(n<4){
        return result;
      }
      sort(nums.begin(),nums.end());

      for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
        for(int j=i+1;j<n-2;j++){
          if(j>i+1 && nums[j]==nums[j-1]) continue;
          if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
          if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
          left=j+1;
          right=n-1;
          while(left<right){
            if(nums[i]+nums[j]+nums[left]+nums[right]<target){
              left++;
            }else if(nums[i]+nums[j]+nums[left]+nums[right]>target){
              right--;
            }else{
              result.push_back({nums[i],nums[j],nums[left],nums[right]});
              left++;
              right--;
              while(left<right && nums[left]==nums[left-1]) left++;
              while(left<right && nums[right]==nums[right+1]) right--;
            }
          }
        }
      }

      return result;
        
    }
};
// @lc code=end
