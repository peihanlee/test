/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (20.55%)
 * Likes:    942
 * Dislikes: 981
 * Total Accepted:    115.6K
 * Total Submissions: 560.8K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      map<long long, int> mp;
      int j=0;
      for(int i=0;i<nums.size();i++){
        if (i-j>k) {
          mp.erase(nums[j]);
          j++;
        }
        map<long long,int>::iterator it=mp.lower_bound((long long)nums[i]-t);
        if (it!=mp.end() && abs(it->first-nums[i])<=t) return true;
        mp[nums[i]]=i;
      }
      return false;
    }
};
// @lc code=end
