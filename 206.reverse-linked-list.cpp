/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (60.15%)
 * Likes:    3849
 * Dislikes: 83
 * Total Accepted:    888.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
      ListNode dummy(0);
      ListNode *pre=&dummy;
      ListNode *cur;
      pre->next=head;
      cur=head;

      while(cur && cur->next){
        ListNode *temp=pre->next;
        pre->next=cur->next;
        cur->next=pre->next->next;
        pre->next->next=temp;
      }
      return pre->next;        
    }
};
// @lc code=end
