/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (38.16%)
 * Likes:    2630
 * Dislikes: 333
 * Total Accepted:    375.1K
 * Total Submissions: 979.1K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if(!head || !head->next){
        return true;
      }

      ListNode *slow=head;
      ListNode *fast=head;

      while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      //revert
      ListNode *tmp;
      ListNode *checkNode = slow->next;
      while(checkNode->next){
        tmp = checkNode->next;
        checkNode->next = tmp->next;
        tmp->next=slow->next;
        slow->next = tmp;
      }

      //Compare
      checkNode = slow->next;
      ListNode *preNode = head;
      while(checkNode){
        if(preNode->val != checkNode->val) return false;
        checkNode = checkNode->next;
        preNode = preNode->next;
      }

      return true;
    }
};
// @lc code=end
