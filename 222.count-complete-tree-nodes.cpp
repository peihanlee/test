/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (41.37%)
 * Likes:    1700
 * Dislikes: 182
 * Total Accepted:    189.3K
 * Total Submissions: 453.2K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
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
    int countNodes(TreeNode* root) {
      TreeNode *tmpNode = NULL;
      int leftDepth=0;
      int rightDepth=0;
      if(!root){
        return 0;
      }

      tmpNode=root;
      while(tmpNode){
        leftDepth++;
        tmpNode=tmpNode->left;
      }
      tmpNode=root;
      while(tmpNode){
        rightDepth++;
        tmpNode=tmpNode->right;
      }

      if(leftDepth == rightDepth){
        return pow(2,leftDepth)-1;
      }else{
        return 1+countNodes(root->left)+countNodes(root->right);
      }
    }
};
// @lc code=end
