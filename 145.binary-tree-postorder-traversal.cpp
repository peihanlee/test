/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (52.78%)
 * Likes:    1460
 * Dislikes: 76
 * Total Accepted:    346.5K
 * Total Submissions: 652.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
      trace(res,root->left);
      trace(res,root->right);
      res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      trace(res,root);
      return res;        
    }
};
// @lc code=end
