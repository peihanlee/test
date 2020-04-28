/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.55%)
 * Likes:    2502
 * Dislikes: 65
 * Total Accepted:    548.6K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    void bfs(vector<vector<int>>& res, vector<TreeNode *> nodes){
      vector<TreeNode *> next_nodes;
      vector<int> vals;
      if(nodes.size()>0){
        for(int i=0; i<nodes.size();i++){
          vals.push_back(nodes[i]->val);
          if(nodes[i]->left){
            next_nodes.push_back(nodes[i]->left);
          }
          if(nodes[i]->right){
            next_nodes.push_back(nodes[i]->right);
          }
        }
        res.push_back(vals);
        bfs(res, next_nodes);
      }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      vector<TreeNode *> nodes;

      if(!root){
        return res;
      }
      nodes.push_back(root);
      bfs(res, nodes);
      return res;
    }
};
// @lc code=end
