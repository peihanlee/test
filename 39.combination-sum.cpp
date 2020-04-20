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
    void checkCombination(vector<vector<int>> &result, vector<int> &combine, int sum, int step, int step_end, vector<int> candidates, int target){
      if(step>=step_end){
        return;
      }

      if(sum==target){
        result.push_back(combine);
        cout<<"Found!!"<<"\n";
        return;
      }

      if(sum>target){
        return;
      }

      cout<<"push:"<<candidates[step]<<"\n";
      combine.push_back(candidates[step]);
      checkCombination(result, combine, sum+candidates[step], step, step_end, candidates, target);
      combine.pop_back();
      cout<<"pop:"<<candidates[step]<<"\n";

      checkCombination(result, combine, sum, step+1, step_end, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> combine;
      vector<vector<int>> result;

      checkCombination(result, combine, 0, 0, candidates.size(), candidates, target);     
      return result; 
    }
};
// @lc code=end
