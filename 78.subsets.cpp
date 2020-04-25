/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (58.41%)
 * Likes:    3111
 * Dislikes: 72
 * Total Accepted:    509.3K
 * Total Submissions: 866.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    void generateList(vector<vector<int>>& result, vector<int>& nums, vector<int>& list, int index, int n){
      if(index == n){
        result.push_back(list);
      }else{
        generateList(result, nums, list, index+1, n);
        list.push_back(nums[index]);
        generateList(result, nums, list, index+1, n);
        list.pop_back();
      }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> list;

      int n=nums.size();
      int index=0;
      generateList(result, nums, list, index, n);
/*
      generateList(result, nums, list, index+1, n);
      list.push_back(nums[index]);
      generateList(result, nums, list, index+1, n);
      list.pop_back();
*/
      return result;
    }
};
// @lc code=end
