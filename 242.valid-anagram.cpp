/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (55.40%)
 * Likes:    1258
 * Dislikes: 131
 * Total Accepted:    510K
 * Total Submissions: 916.2K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size())
       return false;

      unordered_map<int,int> mp;
      int n=s.size();

      for(int i=0;i<n;i++){
        mp[s[i]]++;
      }

      for(int i=0;i<n;i++){
        if(mp[t[i]]==0)
          return false;
        mp[t[i]]--;
      }

      return true;


        
    }
};
// @lc code=end
