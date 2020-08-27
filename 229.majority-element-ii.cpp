/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (34.38%)
 * Likes:    1332
 * Dislikes: 153
 * Total Accepted:    130.5K
 * Total Submissions: 378.1K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> res;
      int n = nums.size();
      int boundary = n/3;
      int a=0;
      int b=0;
      int cnt_a=0;
      int cnt_b=0;

      for(int i=0;i<n;i++){
        if(a==nums[i]){
          cnt_a++;
        }else if(b==nums[i]){
          cnt_b++;
        }else if(cnt_a==0) {
          a=nums[i]; cnt_a++;
        }else if(cnt_b==0) {
          b=nums[i]; cnt_b++;
        }else{cnt_a--; cnt_b--;}
      }

      cnt_a=0;
      cnt_b=0;
      for(int i=0;i<n;i++){
        if(a==nums[i]){
          cnt_a++;
        }else if(b==nums[i]){
          cnt_b++;
        }
      }
      if(cnt_a>boundary) res.push_back(a);
      if(cnt_b>boundary) res.push_back(b);

      return res;
    }
};
// @lc code=end
