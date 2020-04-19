/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.63%)
 * Likes:    1912
 * Dislikes: 159
 * Total Accepted:    432.3K
 * Total Submissions: 884K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
      ListNode **pp=NULL; 
      ListNode *a=NULL;
      ListNode *b=NULL;

      if(head == NULL){
        return head;
      }

      pp=&head;
      while((a=*pp) && (b=a->next)){
        a->next=b->next;
        b->next=a;
        *pp=b;
        pp=&(a->next);
      }

      return head;
    }
};
// @lc code=end
