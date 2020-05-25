/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (39.16%)
 * Likes:    1188
 * Dislikes: 325
 * Total Accepted:    272.9K
 * Total Submissions: 695.8K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int n = s.size();
      vector<int> mapping_s(256,INT_MIN);
      vector<int> mapping_t(256,INT_MIN);

      for(int i=0;i<n;i++){
        if(mapping_s[s[i]]==INT_MIN && mapping_t[t[i]]==INT_MIN){
          mapping_s[s[i]]=i;
          mapping_t[t[i]]=i;
        }else if(mapping_s[s[i]]!= mapping_t[t[i]]){
          return false;
        }
      }
      return true;        
    }
};
// @lc code=end
