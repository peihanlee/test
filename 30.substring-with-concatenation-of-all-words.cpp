/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.84%)
 * Likes:    758
 * Dislikes: 1150
 * Total Accepted:    166.6K
 * Total Submissions: 668.7K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> result={};
      int n=words.size();
      if(n==0 || s.length()==0){
        return result;
      }
      int wLen=words[0].length();

      if(n*wLen>s.length()) return result;
        
      unordered_map<string,int> dict;
      for(int i=0;i<words.size();i++){
        dict[words[i]]++;
      }

      string strCheck="";
      int k=0;
      for(int j=0;j<=s.length()-(n*wLen);j++){
        unordered_map<string,int> seen;
        for(k=0;k<n;k++){
          strCheck=s.substr(j+k*wLen,wLen);
          if(dict.find(strCheck)!=dict.end()){
            seen[strCheck]++;
            if(seen[strCheck]>dict[strCheck]) break;
          }else{
            break;
          }
        }
        if(k==n){
          result.push_back(j);
        }
      }
      return result;
    }
};
// @lc code=end
