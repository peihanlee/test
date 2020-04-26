/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (45.53%)
 * Likes:    1423
 * Dislikes: 61
 * Total Accepted:    258.7K
 * Total Submissions: 566K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void generateList(vector<vector<int>>& result, vector<int>& nums, vector<int>& list, int index, int n){
      if(index == n){
        result.push_back(list);
      }else{
        int repeat=0;
        list.push_back(nums[index]);
        generateList(result, nums, list, index+1, n);
        list.pop_back();
        while(index+repeat+1<n && nums[index]==nums[index+repeat+1]){
          repeat++;
       }
        generateList(result, nums, list, index+repeat+1, n);
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> list;

      int n=nums.size();
      int index=0;
      sort(nums.begin(),nums.end());
      generateList(result, nums, list, index, n);
      return result;
        
    }
};
// @lc code=end
