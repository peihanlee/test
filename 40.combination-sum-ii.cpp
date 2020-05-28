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
    void checkCombination(vector<vector<int>> &result, vector<int> &combine, int sum, int idx, int n, vector<int> candidates, int target){
      if(sum==target){
        result.push_back(combine);
        return;
      }

      if(sum>target){
        return;
      }

      for(int i=idx;i<n;i++){
        if(i!=idx && candidates[i]==candidates[i-1]){
          continue;
        }
        combine.push_back(candidates[i]);
        checkCombination(result, combine, sum+candidates[i], i+1, n, candidates, target);     
        combine.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> combine;
      vector<vector<int>> result;
      int n=candidates.size();

      sort(candidates.begin(),candidates.end());

      checkCombination(result, combine, 0, 0, n, candidates, target);     
      return result; 
    }
};
// @lc code=end
