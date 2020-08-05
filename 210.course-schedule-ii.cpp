/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (38.32%)
 * Likes:    1732
 * Dislikes: 117
 * Total Accepted:    225.7K
 * Total Submissions: 586.2K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> ret;
      queue<int> cq;
      vector<vector<int>> course_list(numCourses);
      int n=prerequisites.size();

      for(int i=0;i<n;i++){
        //cout<<prerequisites[i].front()<<" need "<<prerequisites[i].back()<<"\n";
        course_list[prerequisites[i].front()].push_back(prerequisites[i].back());
      }

      for(int i=0;i<numCourses;i++){
        if(course_list[i].size()==0){
          cq.push(i);
        }
      }

      while(!cq.empty()){
        int c=cq.front();
        //cout<<"C:"<<c<<"\n";
        ret.push_back(c);
        cq.pop();
        for(int i=0;i<numCourses;i++){
          int m=course_list[i].size();
          //cout<<"size:"<<m<<"\n";
          for(int j=m-1;j>=0;j--){
            //cout<<"Multu C:"<<i<<"\n";
            if(course_list[i][j]==c){
              course_list[i].erase(course_list[i].begin()+j);
            }
            if(course_list[i].empty()){
              cq.push(i);
            }
          }
        }
      }
      /*
      for(int i=0;i<numCourses;i++){
        cout<<"size:"<<course_list[i].size()<<"\n";
        course_list[i].push_back(i);
      }

      for(int i=0;i<numCourses;i++){
        cout<<"Next size :"<<course_list[i].size()<<"\n";
        course_list[i].push_back(i);
      }
      */

      if(ret.size()==numCourses){
        return ret;
      }else{
        return {};
      }       
    }
};
// @lc code=end
