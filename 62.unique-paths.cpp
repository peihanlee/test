/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    2640
 * Dislikes: 187
 * Total Accepted:    417.2K
 * Total Submissions: 804.5K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 100
 * It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_map<string,int> cache;

    int uniquePaths(int m, int n) {
      int result;
      if(cache.find(to_string(m)+"x"+to_string(n))!=cache.end()){
        return cache[to_string(m)+"x"+to_string(n)];
      }

      if(m==1 && n==1){
        result=1;
      }else if(m==1){
        result=uniquePaths(m,n-1);
      }else if(n==1){
        result=uniquePaths(m-1,n);
      }else{
        result=uniquePaths(m,n-1)+uniquePaths(m-1,n);
      }        
      cache[to_string(m)+"x"+to_string(n)] = result;
      return result;

    }
};
// @lc code=end
