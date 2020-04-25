/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (35.52%)
 * Likes:    1371
 * Dislikes: 100
 * Total Accepted:    232K
 * Total Submissions: 649.9K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
      if(head==NULL || head->next==NULL){
        return head;
      }

      while(head->val == head->next->val){
        if(head->next->next == NULL || head->val != head->next->next->val){
          return deleteDuplicates(head->next->next);
        }else{
          head->next=head->next->next;
        }      
      }
      head->next=deleteDuplicates(head->next);
      return head;      
    }
};
// @lc code=end
