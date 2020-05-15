/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (54.21%)
 * Likes:    1266
 * Dislikes: 54
 * Total Accepted:    454.2K
 * Total Submissions: 835K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
    void trace(vector<int>& res, TreeNode* root){
      if(!root){
        return;
      }
      res.push_back(root->val);
      trace(res,root->left);
      trace(res,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      trace(res,root);
      return res;        
    }
};
// @lc code=end
