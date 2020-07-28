/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (37.98%)
 * Likes:    637
 * Dislikes: 247
 * Total Accepted:    152.1K
 * Total Submissions: 399.4K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_map<size_t,int> mp;
      hash<string> ht;
      int n=s.size();
      vector<string> ret;

      for(int i;i<=n-10;i++){
        if(mp[ht(s.substr(i,10))]++==1){
          ret.push_back(s.substr(i,10));
        }
      }
      return ret;
        
    }
};
// @lc code=end
