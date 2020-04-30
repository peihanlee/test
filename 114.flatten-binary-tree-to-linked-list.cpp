/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (46.84%)
 * Likes:    2327
 * Dislikes: 283
 * Total Accepted:    314.4K
 * Total Submissions: 667K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    TreeNode *create(TreeNode* root){
      if(!root){
        return NULL;
      }
      TreeNode *leftNode=create(root->left);
      TreeNode *rightNode=create(root->right);
      if(!leftNode && !rightNode){
        return root;
      }else if(leftNode && rightNode){
        leftNode->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return rightNode;
      }else if(leftNode){
        root->right=root->left;
        root->left=NULL;
        return leftNode;
      }else{
        return rightNode;
      }
    }

    void flatten(TreeNode* root) {
      create(root);
    }
};
// @lc code=end
