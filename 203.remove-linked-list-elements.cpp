/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (37.24%)
 * Likes:    1312
 * Dislikes: 78
 * Total Accepted:    297.8K
 * Total Submissions: 798K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode *cur;
      ListNode dummy(0);
      dummy.next=head;

      cur=&dummy;

      while(cur && cur->next){
        if(cur->next->val==val){
          if(cur->next==head){
            cur->next=cur->next->next;
            head=cur->next;
          }else{
            cur->next=cur->next->next;
          }
        }else{
          cur=cur->next;
        }
      }
      return head;        
    }
};
// @lc code=end
