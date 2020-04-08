/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 *
 * https://leetcode.com/problems/h-index/description/
 *
 * algorithms
 * Medium (35.22%)
 * Likes:    527
 * Dislikes: 891
 * Total Accepted:    142.7K
 * Total Submissions: 405.1K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * Given an array of citations (each citation is a non-negative integer) of a
 * researcher, write a function to compute the researcher's h-index.
 * 
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N −
 * h papers have no more than h citations each."
 * 
 * Example:
 * 
 * 
 * Input: citations = [3,0,6,1,5]
 * Output: 3 
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
 * of them had 
 * ⁠            received 3, 0, 6, 1, 5 citations respectively. 
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining 
 * two with no more than 3 citations each, her h-index is 3.
 * 
 * Note: If there are several possible values for h, the maximum one is taken
 * as the h-index.
 * 
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
      int n=citations.size();
      int i;

      if(n == 0){
        return 0;
      }

      sort(citations.begin(),citations.end());
      i = 0;
      while(i<n && citations[i]< n-i){
        //cout<<"citations[i]:"<<citations[i]<<","<<n-i<<"\n";
        i++;
      }

      return n-i;


        
    }
};
// @lc code=end