/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (52.86%)
 * Likes:    3187
 * Dislikes: 224
 * Total Accepted:    560.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      int n=nums.size();

      for(int i=n-1;i>=n-k;i--){
        for(int j=0;j<i;j++){
          if(nums[j]>nums[j+1]){
            swap(nums[j],nums[j+1]);
          }
        }
      }
      return nums[n-k];
        
    }
};
// @lc code=end
