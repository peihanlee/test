/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.14%)
 * Likes:    3419
 * Dislikes: 256
 * Total Accepted:    519.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
      return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int index=0;
      vector<vector<int>> res;
      int n=intervals.size();

      if(n==0)
        return res;

      sort(intervals.begin(),intervals.end(),comp);
      res.push_back(intervals[index]);
      index++;
      while(index<n){
        if(res.back()[1]<intervals[index][0]){
          res.push_back(intervals[index]);
        }
        else{
          res.back()[0] = min(res.back()[0],intervals[index][0]);
          res.back()[1] = max(res.back()[1],intervals[index][1]);
        }
        index++;
      }

      return res;        
    }
};
// @lc code=end
