/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (52.81%)
 * Likes:    1404
 * Dislikes: 550
 * Total Accepted:    366.8K
 * Total Submissions: 692.7K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int l=0;
      int r=numbers.size()-1;
      vector<int> res;

      while(l<r){
        if(numbers[l]+numbers[r]>target){
          r--;
        }else if(numbers[l]+numbers[r]<target){
          l++;
        }else{
          res.push_back(l+1);
          res.push_back(r+1);
          break;
        }
      }
      return res;
    }
};
// @lc code=end
