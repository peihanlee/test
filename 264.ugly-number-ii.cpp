/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (38.88%)
 * Likes:    1399
 * Dislikes: 85
 * Total Accepted:    134.4K
 * Total Submissions: 344.7K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
      vector<int> list(1,1);
      vector<int> factors={2,3,5};
      vector<int> index(3,0);

      while(list.size()<n){
        int min_number = INT_MAX;

        for(int i=0;i<factors.size();i++){
          min_number = min(min_number,factors[i]*list[index[i]]);
        }

        list.push_back(min_number);

        for(int i=0;i<factors.size();i++){
          if(factors[i]*list[index[i]]==min_number){
            index[i]++;
          }
        }
      }
      return list[n-1];
       
    }
};
// @lc code=end
