/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.55%)
 * Likes:    1679
 * Dislikes: 87
 * Total Accepted:    320.8K
 * Total Submissions: 700.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<int> getLevelVals(int size, int leftFirst, vector<TreeNode *> src, vector<TreeNode *> &des){
      vector<int> vals;
      for(int i=size-1;i>=0;i--){
          vals.push_back(src[size-1-i]->val);
        if(leftFirst){
          if(src[i]->left){
            des.push_back(src[i]->left);
          }
          if(src[i]->right){
            des.push_back(src[i]->right);
          }
        }else{
          if(src[i]->right){
            des.push_back(src[i]->right);
          }
          if(src[i]->left){
            des.push_back(src[i]->left);
          }
        }
      }
      return vals;
    }

    void bfs(vector<vector<int>>& res, vector<TreeNode*> leftToR, vector<TreeNode*> rightToL){
      int l=leftToR.size();
      int r=rightToL.size();
      vector<TreeNode *> nextLToR;
      vector<TreeNode *> nextRToL;
      if(l || r){
        if(l){
          res.push_back(getLevelVals(l,0,leftToR,nextRToL));
        }else{
          res.push_back(getLevelVals(r,1,rightToL,nextLToR));
        }
        bfs(res,nextLToR,nextRToL);
      }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      vector<TreeNode*> leftToR;
      vector<TreeNode*> rightToL;

      if(!root){
        return res;
      }
      leftToR.push_back(root);
      bfs(res,leftToR,rightToL);   
      return res;     
    }
};
// @lc code=end
