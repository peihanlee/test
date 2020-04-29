/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (42.68%)
 * Likes:    1912
 * Dislikes: 151
 * Total Accepted:    415.9K
 * Total Submissions: 972.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
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
    int checkDepth(TreeNode* root, int depth, bool& balanced){
      if(!root || !balanced){
        return depth;
      }else{
        depth++;
        int leftDepth = checkDepth(root->left, depth, balanced);
        int rightDepth = checkDepth(root->right, depth, balanced);

        if(balanced){
          balanced = abs(leftDepth-rightDepth)<=1;
        }
                
        return max(leftDepth, rightDepth);        
      }
    }

    bool isBalanced(TreeNode* root) {
      int depth=0;
      int total=0;
      bool balanced = true;
      if(!root) return balanced;
      //cout<<"depth:"<<depth<<", total:"<<total<<"\n";
      checkDepth(root, depth, balanced);

      return balanced;

      //return (((1<<(depth-1))-1)<=total) && (total<=((1<<depth)-1));
        
    }
};
// @lc code=end
