/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (44.93%)
 * Likes:    3293
 * Dislikes: 374
 * Total Accepted:    542.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution {
public:
    void pad_mapping(vector<string> &res, int position, string &digits, string &str, vector<string> &pad){
      if( position == digits.size()){
        res.push_back(str);
        //cout<<str<<"\n";
      } else {
        int i;

        for(i=0;i<pad[digits[position]-'0'].size();i++){
          str.push_back(pad[digits[position]-'0'][i]);          
          //cout<<str<<"]\n";
          pad_mapping(res, position+1, digits, str, pad);
          str.pop_back();
        }
      }
    }


    vector<string> letterCombinations(string digits) {
      vector<string> pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      vector<string> res;
      string str="";
      int i;

      if(digits.size()==0){
        return res;
      }
      pad_mapping(res, 0, digits, str, pad);
      return res;
    }
};
// @lc code=end
