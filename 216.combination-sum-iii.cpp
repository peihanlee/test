/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (54.85%)
 * Likes:    898
 * Dislikes: 47
 * Total Accepted:    154.7K
 * Total Submissions: 280.9K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void checkCombination(vector<vector<int>> &result, vector<int> &combine, int sum, int start_i, int idx, int k, int target){
      if(sum==target && idx==k){
        result.push_back(combine);
        return;
      }

      if(sum>target || idx>k){
        return;
      }

      for(int i=start_i;i<10;i++){
        combine.push_back(i);
        checkCombination(result, combine, sum+i, i+1, idx+1, k, target);     
        combine.pop_back();
      }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int> combine;
      vector<vector<int>> result;
      checkCombination(result, combine, 0, 1, 0, k, n);     
      return result; 
        
    }
};
// @lc code=end
