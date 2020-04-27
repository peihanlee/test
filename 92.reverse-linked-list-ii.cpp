/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (37.50%)
 * Likes:    1943
 * Dislikes: 127
 * Total Accepted:    251.3K
 * Total Submissions: 667.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode *pre, *cur=head;
      ListNode *dummy = new ListNode(0);
      int i=1;
      dummy->next = head;
      pre=dummy;

      while(cur!=NULL && m!=n){
        if(i==m){
          pre=cur;
        }else if(i>m){
          cur=pre->next;
          pre->next=cur->next;
          cur->next=dummy->next;;
          dummy->next=cur;
          cur=pre;
          if(i==n){
            break;
          }
        }else{
          dummy=dummy->next;
        }
        i++;
        cur=cur->next;
      }
      if(m==1){
        head=dummy->next;
      }
      return head;
    }
};
// @lc code=end
