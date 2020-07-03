/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (41.06%)
 * Likes:    3101
 * Dislikes: 157
 * Total Accepted:    344.9K
 * Total Submissions: 836.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> g(numCourses);
      vector<int> in(numCourses, 0);
      queue<int> q;

      for(int i=0;i<prerequisites.size();i++){
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        in[prerequisites[i][0]]++;
      }

      for(int i=0;i<numCourses;i++){
        if(in[i]==0){
          q.push(i);
        }
      }

      while(!q.empty()){
        int c = q.front();
        for(int i=0;i<g[c].size();i++){
          in[g[c][i]]--;
          if(in[g[c][i]]==0){
            q.push(g[c][i]);
          }
        }
        q.pop();
      }

      for(int i=0;i<numCourses;i++){
        if(in[i]!=0){
          return false;
        }
      }
      return true;
        
    }
};
// @lc code=end
