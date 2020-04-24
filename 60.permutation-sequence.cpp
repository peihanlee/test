/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (35.46%)
 * Likes:    1252
 * Dislikes: 293
 * Total Accepted:    169.3K
 * Total Submissions: 475.5K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPmt(vector<int> &nums,int n){
      for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
          int check=i+1;
          sort(nums.begin()+i+1, nums.end());
          while(nums[check]<nums[i]) check++;
          swap(nums[i],nums[check]);
          return;
        }
      }
      sort(nums.begin(),nums.end());
    }

    string getPermutation(int n, int k) {
      string res="";
      if(n == 0){
        return "";
      }else if(n==1){
        return "1";
      }
      vector<int> nums(n);

      for(int i=0;i<n;i++){
        nums[i]=i+1;
      }

      for(int i=0;i<k-1;i++){
        nextPmt(nums,n);
      }

      for(int i=0;i<n;i++){
        //res.append(nums[i]+'0');
        res+=to_string(nums[i]);
      }
      return res; 
    }
};
// @lc code=end
