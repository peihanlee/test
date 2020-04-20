/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (39.97%)
 * Likes:    1837
 * Dislikes: 346
 * Total Accepted:    245.6K
 * Total Submissions: 610.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
      int list_len=0;
      ListNode *pre=head;
      while(pre){
        list_len++;
        pre=pre->next;
      }

      ListNode *temp=NULL;
      ListNode *dummy=new ListNode(0);
      dummy->next = head; pre=dummy;
      for(int i=0;i<list_len/k;i++){
        for(int j=1;j<k;j++){
          temp = pre->next;
          pre->next=head->next;
          head->next=head->next->next;
          pre->next->next=temp;
        }
        pre=head;
        head=head->next;
      }
      return dummy->next;        
    }
};
// @lc code=end
