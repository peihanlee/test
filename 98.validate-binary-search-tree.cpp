/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.20%)
 * Likes:    3321
 * Dislikes: 472
 * Total Accepted:    618.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 */

// @lc code=start
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
    bool checkLR(TreeNode* root, long min_val, long max_val){
      bool res=true;
      res = (root->val>min_val) && (root->val<max_val);
      if(res && root->left){
        //res = (root->val>root->left->val) && (checkLR(root->left, min_val, min(root->val,max_val))); 
        res = (root->val>root->left->val) && (checkLR(root->left, min_val, root->val)); 
      }
      if(res && root->right){
        //res = (root->val<root->right->val) && (checkLR(root->right, max(min_val,root->val), max_val));
        res = (root->val<root->right->val) && (checkLR(root->right, root->val, max_val));
      }
      return res;
    }
    bool isValidBST(TreeNode* root) {
      if(root==NULL){
        return true;
      }
      return checkLR(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
