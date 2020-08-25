/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (37.18%)
 * Likes:    363
 * Dislikes: 663
 * Total Accepted:    102.1K
 * Total Submissions: 273.8K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      if(F>=D || B>=H || E>=C || A>=G)
        return (C-A)*(D-B)+(G-E)*(H-F);
      else
        return (C-A)*(D-B)-(min(D,H) - max(B,F))*(min(C,G) - max(A,E)) +(G-E)*(H-F);
    }
};
// @lc code=end
