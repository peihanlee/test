/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.69%)
 * Likes:    1321
 * Dislikes: 149
 * Total Accepted:    225.5K
 * Total Submissions: 689.8K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int index = 0;
      vector<vector<int>> res;
      vector<int> tmp(2);

      while(index < intervals.size() && intervals[index][1] < newInterval[0]){
        res.push_back(intervals[index]);
        cout<<"["<<intervals[index][0]<<","<<intervals[index][1]<<"]\n";
        index++;
      }
      tmp[0] = newInterval[0];
      tmp[1] = newInterval[1];
      while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
        tmp[0] = min(tmp[0],intervals[index][0]);
        tmp[1] = max(tmp[1],intervals[index][1]);
        index++;        
      }
      cout<<"tmp ["<<tmp[0]<<","<<tmp[1]<<"]\n";
      res.push_back(tmp);

      while(index < intervals.size()){
        res.push_back(intervals[index]);
        cout<<"["<<intervals[index][0]<<","<<intervals[index][1]<<"]\n";
        index++;
      }

      return res;
    }
};
// @lc code=end
