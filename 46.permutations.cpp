/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (60.82%)
 * Likes:    3320
 * Dislikes: 95
 * Total Accepted:    545.9K
 * Total Submissions: 892.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3]
 * ⁠ [1,3,2]
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findNext(vector<int>& nums){
      int n=nums.size();
      for(int i=n-2;i>=0;i--){
        if(nums[i+1]>nums[i]){
          sort(nums.begin()+i+1,nums.end());
          for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]){
              swap(nums[j], nums[i]);
              return nums;
            }
          }
        }
      }
      sort(nums.begin(),nums.end());
      return nums;
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> start=nums;

      do{
          result.push_back(nums);
          nums=findNext(nums);
      }
      while(nums!=start);
      return result;  
    }
};
// @lc code=end
