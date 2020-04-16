/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.83%)
 * Likes:    2826
 * Dislikes: 202
 * Total Accepted:    560K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* pre_start = head;
      ListNode* start = head;
      ListNode* end = head;
      if(n == 0){
        return head;
      }

      //Go n first
      while(n>0 && end!=NULL)
      {
        end=end->next;
        n--;
      }

      if(end==NULL){
        head=head->next;
      }else{
        while(end!=NULL){
          pre_start=start;
          start=start->next;
          end=end->next;
        }
        pre_start->next=start->next;
        delete start;
      }
      return head; 
    }
};
// @lc code=end
