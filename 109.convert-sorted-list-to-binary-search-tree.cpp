/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (45.38%)
 * Likes:    1668
 * Dislikes: 84
 * Total Accepted:    226K
 * Total Submissions: 494.8K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if(!head) return NULL;
      if(!head->next) return new TreeNode(head->val);
      ListNode *pre,*slow,*fast;
      slow=head;
      fast=head;
      while(fast && fast->next){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
      }
      pre->next=NULL;
      
      TreeNode *root=new TreeNode(slow->val);
      TreeNode *leftNode=sortedListToBST(head);
      TreeNode *rightNode=sortedListToBST(slow->next);

      root->left=leftNode;
      root->right=rightNode;

      return root;
    }
};
// @lc code=end
