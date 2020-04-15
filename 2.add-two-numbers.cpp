/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.94%)
 * Likes:    7511
 * Dislikes: 1942
 * Total Accepted:    1.3M
 * Total Submissions: 3.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(l1 == NULL && l2 == NULL){
        return NULL;
      }else if(l1 == NULL){
        return l2;
      }else if(l2 == NULL){
        return l1;
      }

      int val = l1->val+l2->val;
      int carry=val/10;
      val = val%10;

      ListNode* p = new ListNode(val);
      p->next = addTwoNumbers(l1->next, l2->next);
      if(carry>0){
        p->next = addTwoNumbers(p->next,new ListNode(1));
      }

      return p;        
    }
};
// @lc code=end
