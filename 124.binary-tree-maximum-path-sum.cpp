/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (32.49%)
 * Likes:    2825
 * Dislikes: 240
 * Total Accepted:    293.3K
 * Total Submissions: 898.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
    int getMax(TreeNode* root, int& maxSum){
      if(!root){
        return 0;
      }
      int leftMax = 0;
      int rightMax = 0;

      leftMax = max(0,getMax(root->left,maxSum));
      rightMax = max(0,getMax(root->right,maxSum));

      maxSum=max(maxSum, leftMax+rightMax+root->val);

      return max(leftMax,rightMax)+root->val;
    }
    int maxPathSum(TreeNode* root) {
      int maxSum=INT_MIN;
      getMax(root,maxSum);
      return maxSum;
    }
};
// @lc code=end
