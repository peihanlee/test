/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (40.01%)
 * Likes:    1068
 * Dislikes: 267
 * Total Accepted:    201.2K
 * Total Submissions: 500.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
      if(head==NULL){
        return head;
      }
      ListNode *preHead=new ListNode(0);
      ListNode *pre=preHead;
      ListNode *postHead=new ListNode(0);
      ListNode *post=postHead;

      while(head!=NULL){
        if(head->val<x){
          pre->next=head;
          pre=pre->next;
        }else{
          post->next=head;
          post=post->next;
        }
        head=head->next;
      }

      post->next=NULL;
      pre->next=postHead->next;

      return preHead->next;
    }
};
// @lc code=end
