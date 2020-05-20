/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (27.64%)
 * Likes:    1597
 * Dislikes: 190
 * Total Accepted:    166.2K
 * Total Submissions: 599K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */

// @lc code=start
class Solution {
public:
    static bool mycompare(int a, int b){
      return to_string(a)+to_string(b)<to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
      string res="";
      sort(nums.begin(),nums.end(),mycompare);        

      for(int i=0;i<nums.size();i++){
        res=to_string(nums[i])+res;
      }
      if(res.size()>0 && res[0]=='0'){
        res = "0";
      }
      return res;
    }
};
// @lc code=end
