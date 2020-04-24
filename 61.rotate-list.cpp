/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (29.06%)
 * Likes:    983
 * Dislikes: 966
 * Total Accepted:    250.1K
 * Total Submissions: 857.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
      ListNode *dummy=new ListNode(0);
      
      if(k==0 || head==NULL){
        return head;
      }
      
      dummy->next=head;
      ListNode *pre=dummy;
      ListNode *last=head;
      int length=0;
      int step=0;

      while(last!=NULL){
        length++;
        last=last->next;
      }

      k=k%length;
      
      if(length==1 || k==0){
        return head;
      }

      step=0;
      while(step<(length-k)){
        step++;
        pre=pre->next;
      }
      last=pre->next;
      while(last->next!=NULL){
        last=last->next;
      }
      last->next=head;
      head=pre->next;
      pre->next=NULL;

      return head;     
    }
};
// @lc code=end
