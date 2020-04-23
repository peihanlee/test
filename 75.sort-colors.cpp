/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    2700
 * Dislikes: 198
 * Total Accepted:    431.5K
 * Total Submissions: 956.4K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int i=0,j=0,k=nums.size()-1;

      while(j<=k){
        if(nums[j]==0){
          swap(nums[i],nums[j]);
          i++;
          j++;
        }else if(nums[j]==2){
          swap(nums[j],nums[k]);
          k--;
        }else{
          j++;
        }
        //cout<<nums[0]<<","<<nums[1]<<","<<nums[2]<<","<<nums[3]<<","<<nums[4]<<","<<nums[5]<<"["<<i<<","<<j<<","<<k<<"]"<<"\n";
      }        
    }
};
// @lc code=end
