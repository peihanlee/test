/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (39.90%)
 * Likes:    2299
 * Dislikes: 116
 * Total Accepted:    242.9K
 * Total Submissions: 603.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* merge(ListNode* l1, ListNode* l2){
      if(!l1){
        return l2;
      }
      if(!l2){
        return l1;
      }

      if(l1->val > l2->val){
        l2->next = merge(l1,l2->next);
        return l2;
      }else{
        l1->next = merge(l1->next,l2);
        return l1;
      }
    }
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next){
        return head;
      }
      ListNode dummy(0);
      dummy.next=head;
      ListNode *slow = &dummy;
      ListNode *fast = &dummy;

      while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
      }

      ListNode *l1=head;
      ListNode *l2=slow->next;
      slow->next=NULL;

      return merge(sortList(l1),sortList(l2));
    }
};
// @lc code=end
