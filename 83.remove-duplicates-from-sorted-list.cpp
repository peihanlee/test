/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.47%)
 * Likes:    1255
 * Dislikes: 100
 * Total Accepted:    428.7K
 * Total Submissions: 961.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
#if 0      
      ListNode *comNode = head;
      ListNode *curNode = head;
      int i=0;
      
      while(i<1 && curNode!=NULL){
        i++;
        curNode=curNode->next;
      }

      while(curNode!=NULL){
        if(curNode->val!=comNode->val){
          comNode->next = curNode;
          comNode=comNode->next;
        }
        curNode=curNode->next;
      }
      if(comNode!=NULL){
        comNode->next=NULL;
      }

      return head;     
#else
      if(head && (head->next=deleteDuplicates(head->next)) && head->next && head->val==head->next->val){
        return head->next;
      }else{
        return head;
      }
#endif      
    }
};
// @lc code=end
