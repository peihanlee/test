/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (56.15%)
 * Likes:    2659
 * Dislikes: 208
 * Total Accepted:    534.5K
 * Total Submissions: 948.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int a=0;
      int cnt_a=0;
      int n=nums.size();

      for(int i=0;i<n;i++){
        if(cnt_a==0){
          a=nums[i]; cnt_a++;
        }else if(a==nums[i]){
          cnt_a++;
        }else{
          cnt_a--;
        }
      }
      return a;  //Always exist!        
    }
};
// @lc code=end
