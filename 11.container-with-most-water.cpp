/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    5264
 * Dislikes: 544
 * Total Accepted:    588.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
      int max_water=0;
      int h=0;
      int i=0;
      int j=height.size()-1;

      while(i<j){
        h=min(height[i],height[j]);
        max_water=max(max_water,h*(j-i));
        while(height[i]<=h && i<j) i++;
        while(height[j]<=h && i<j) j--;
      }
      return max_water;
        
    }
};
// @lc code=end
