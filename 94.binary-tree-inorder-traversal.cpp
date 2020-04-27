/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (61.20%)
 * Likes:    2649
 * Dislikes: 116
 * Total Accepted:    663.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void nextNode(vector<int>& result, TreeNode* root){
      if(root!=NULL){
        nextNode(result,root->left);
        result.push_back(root->val);
        nextNode(result,root->right);
      }
    }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;

      nextNode(result, root);

      return result;
    }
};
// @lc code=end
