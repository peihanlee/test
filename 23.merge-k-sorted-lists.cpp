/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (38.52%)
 * Likes:    3940
 * Dislikes: 254
 * Total Accepted:    570.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* go_merge(ListNode* l1, ListNode* l2){
      ListNode* start = NULL;
      ListNode* head = NULL;

      if(l1 != NULL && l2 ==NULL)
      {
        return l1;
      }

      if(l2 != NULL && l1 ==NULL)
      {
        return l2;
      }
      while(l1!=NULL && l2!=NULL){
        if(l1->val<l2->val){
          if(start == NULL){
            start = l1;
            head = start;
          } else {
            head->next = l1;
            head = head->next;
          }
          l1 = l1->next;
        } else {
          if(start == NULL){
            start = l2;
            head = start;
          } else {
            head->next = l2;
            head = head->next;
          }
          l2 = l2->next;
        }
      }

      if(l1!=NULL)
      {
        head->next = l1;
      }
      if(l2!=NULL)
      {
        head->next = l2;
      }

      return start;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int i=0;
      int j=0;
      int interval=0;

      if(lists.size()==0)
      {
        return NULL;
      }

      for(i=1;i<lists.size();i=i*2){
        interval = i*2;
        for(j=0;(j+i)<lists.size();j+=interval){
          lists[j]=go_merge(lists[j],lists[j+i]);
        }       
      }

      return lists[0];
    }
};
// @lc code=end
