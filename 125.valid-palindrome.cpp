/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (34.45%)
 * Likes:    990
 * Dislikes: 2658
 * Total Accepted:    522.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
      int end=s.size()-1;
      int start=0;

      while(start<end){
        while((start<end) && !((s[start]>='a' && s[start]<='z') || (s[start]>='A' && s[start]<='Z') || (s[start]>='0' && s[start]<='9')) )
        {
          start++;
        }
        while((start<end) && !((s[end]>='a' && s[end]<='z') || (s[end]>='A' && s[end]<='Z') || (s[end]>='0' && s[end]<='9')))
        {
          end--;
        }
        if((start<end) && (tolower(s[start]) != tolower(s[end])))
        {
          cout<<"start:"<<start<<", end:"<<end<<"\n";
          return false;
        }
        start++;
        end--;
      }
      return true;
    }
};
// @lc code=end
