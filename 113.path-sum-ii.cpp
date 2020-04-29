/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (44.66%)
 * Likes:    1457
 * Dislikes: 51
 * Total Accepted:    304.8K
 * Total Submissions: 678.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    void checkSum(vector<vector<int>>& res, vector<int>& list, TreeNode* root, int sum){
      if(!root){
        return;
      }else if(!root->left && !root->right && sum==root->val){
        list.push_back(root->val);
        res.push_back(list);
        list.pop_back();
      }else{ 
        list.push_back(root->val);
        checkSum(res, list, root->left, sum-root->val);
        checkSum(res, list, root->right, sum-root->val);
        list.pop_back();
      }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<int> list;
      vector<vector<int>> res;
      checkSum(res, list, root, sum);
      return res;  
    }
};
// @lc code=end
