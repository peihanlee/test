/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (52.46%)
 * Likes:    1243
 * Dislikes: 62
 * Total Accepted:    267.4K
 * Total Submissions: 506.8K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void generateList(vector<vector<int>>& result, vector<int>& nums, int index, int n, int k){
      if(k==0){
        result.push_back(nums);
      }else if((n-index+1)>=k){
        generateList(result,nums,index+1,n,k);
        nums.push_back(index);
        generateList(result,nums,index+1,n,k-1);
        nums.pop_back();
      }
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> result;
      vector<int> nums;
      int index=1;

      if(k>0 && n>=k){
        generateList(result,nums,index,n,k);
      }
      return result;
    }
};
// @lc code=end
