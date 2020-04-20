/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (45.98%)
 * Likes:    1460
 * Dislikes: 56
 * Total Accepted:    298.9K
 * Total Submissions: 646.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void checkCombination(vector<vector<int>> &result, vector<int> &combine, int sum, int step, int step_end, vector<int> candidates, int target){
      int gap=1;
      if(sum==target){
        result.push_back(combine);
        return;
      }
      
      if(step>=step_end){
        return;
      }

      if(sum>target){
        return;
      }

      combine.push_back(candidates[step]);
      checkCombination(result, combine, sum+candidates[step], step+1, step_end, candidates, target);
      combine.pop_back();
      while(step+gap<step_end && candidates[step]==candidates[step+gap]){
        gap++;
      }
      checkCombination(result, combine, sum, step+gap, step_end, candidates, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> combine;
      vector<vector<int>> result;

      sort(candidates.begin(),candidates.end());

      checkCombination(result, combine, 0, 0, candidates.size(), candidates, target);     
      return result; 
    }
};
// @lc code=end
