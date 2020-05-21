/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.76%)
 * Likes:    1698
 * Dislikes: 540
 * Total Accepted:    326.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
      if(n<2){
        return 0;
      }
      int count=0;
      vector<bool> prime(n,true);

      prime[0]=false;
      prime[1]=false;

      for(int i=2; i*i<n;i++){
        if(prime[i]){
          for(int j=2;i*j<n;j++){
            prime[i*j]=false;
          }
        }
      }
      for(int i=0;i<n;i++){
        if(prime[i]) count++;
      }
      return count;
    }
};
// @lc code=end
