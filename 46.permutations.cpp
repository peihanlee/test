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
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
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
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> start=nums;
      int n=nums.size();
      int i=n-2;

      result.push_back(start);
      while(i>=0){
        for(i=n-2;i>=0;i--){
          if(nums[i+1]>nums[i]){
            sort(nums.begin()+i+1,nums.end());
            for(int j=i+1;j<n;j++){
              if(nums[j]>nums[i]){
                swap(nums[j], nums[i]);
                if(start!=nums){
                  result.push_back(nums);
                }else{
                  return result;
                }
                break;
              }
            }
            break;
          }
        }
        if(i<0){
          sort(nums.begin(),nums.end());
          if(start!=nums){
            result.push_back(nums);
            i=n-2;
          }
          else{
            cout<<"found start!!\n";
          }
        }
      }
      return result;  
    }
};
// @lc code=end
