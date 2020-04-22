/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (53.20%)
 * Likes:    3068
 * Dislikes: 166
 * Total Accepted:    614.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> result;
      unordered_map<string,vector<string>> dict;

      string sort_str;
      for(int i=0;i<strs.size();i++){
        sort_str=strs[i];
        sort(sort_str.begin(),sort_str.end());
        dict[sort_str].push_back(strs[i]);
      }

      unordered_map<string,vector<string>>::iterator it;
      for(it=dict.begin();it!=dict.end();it++){
        result.push_back(it->second);
      }
      return result;
      
        
    }
};
// @lc code=end
