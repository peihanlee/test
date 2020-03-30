/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (44.00%)
 * Likes:    2733
 * Dislikes: 161
 * Total Accepted:    269.8K
 * Total Submissions: 613K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int i;
      int left,right;
      int sum;
      int longest=0;
      unordered_map<int,int> table;

      for(i=0;i<nums.size();i++){
        cout<<"i:"<<i<<"num[i]:"<<nums[i]<<"\n";
        if(table[nums[i]]==0){
          left = table[nums[i]-1];
          right = table[nums[i]+1];
          sum = left+right+1;
          table[nums[i]]= table[nums[i]-left]= table[nums[i]+right] = sum;          
          cout<<nums[i]<<","<<nums[i]-left<<","<<nums[i]+right<<",("<<sum<<")\n";
          longest = max(longest,sum);
        }
      }

      return longest;  
    }
};
// @lc code=end
