/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (53.74%)
 * Likes:    3218
 * Dislikes: 102
 * Total Accepted:    489.8K
 * Total Submissions: 906.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void checkCombination(vector<vector<int>> &result, vector<int> &combine, int sum, int idx, int n, vector<int> candidates, int target){
      if(sum==target){
        result.push_back(combine);
        return;
      }

      if(sum>target){
        return;
      }

      for(int i=idx;i<n;i++){
        combine.push_back(candidates[i]);
        checkCombination(result, combine, sum+candidates[i], i, n, candidates, target);     
        combine.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> combine;
      vector<vector<int>> result;

      int n=candidates.size();
      checkCombination(result, combine, 0, 0, n, candidates, target);     
      return result; 
    }
};
// @lc code=end
