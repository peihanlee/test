/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (51.99%)
 * Likes:    1824
 * Dislikes: 103
 * Total Accepted:    250K
 * Total Submissions: 478.5K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ret;
      queue<TreeNode *> nodeQueue;
      int n;
      if(!root){
        return ret;
      }
      nodeQueue.push(root);

      n = nodeQueue.size();
      while(n!=0){
        TreeNode *lastNode;
        for(int i=0;i<n;i++){
          lastNode=nodeQueue.front();
          if(lastNode->left) nodeQueue.push(lastNode->left);
          if(lastNode->right) nodeQueue.push(lastNode->right);

          nodeQueue.pop();
        }
        ret.push_back(lastNode->val);
        n = nodeQueue.size();
      }

      return ret;
    }
};
// @lc code=end
