/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (51.68%)
 * Likes:    3622
 * Dislikes: 539
 * Total Accepted:    904.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* result = NULL;
      if(l1==NULL && l2==NULL){
        return NULL;
      }else if(l1==NULL){
        return l2;
      }else if(l2==NULL){
        return l1;
      }

      if(l1->val < l2->val){
        result = l1;
        l1=l1->next;
      }else{
        result = l2;
        l2=l2->next;
      }
      result->next=mergeTwoLists(l1,l2);
      return result;
    }
};
// @lc code=end
