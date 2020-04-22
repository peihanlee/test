/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.56%)
 * Likes:    1664
 * Dislikes: 57
 * Total Accepted:    324.4K
 * Total Submissions: 724.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
