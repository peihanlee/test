/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (49.40%)
 * Likes:    1373
 * Dislikes: 89
 * Total Accepted:    286.7K
 * Total Submissions: 579.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    void findPath(TreeNode *node, string str, vector<string> &res){
      string::iterator it;
      
      if(node){
        if(!str.empty()){
          str+="->";
        }
        str+=to_string(node->val);
        if(node->left){
          findPath(node->left, str, res);
        }
        if(node->right){
          findPath(node->right, str, res);
        }
        if(!node->left && !node->right){
          res.push_back(str);
        }
      }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
      string str;
      vector<string> res;

      if(root)
      {
        findPath(root,"",res);
      }

      return res;        
    }
};
// @lc code=end
