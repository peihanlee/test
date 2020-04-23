/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (46.31%)
 * Likes:    3666
 * Dislikes: 120
 * Total Accepted:    610.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_map<int,int> cache;
    int climbStairs(int n) {
      int result;
      if(n<=1){
        return 1;
      }else{
        if(cache.find(n)!=cache.end()){
          return cache[n];
        }else{
          result = climbStairs(n-1)+climbStairs(n-2);     
          cache[n]=result;
          return result;
        }
      }
    }
};
// @lc code=end
