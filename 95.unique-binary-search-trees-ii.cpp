/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (38.82%)
 * Likes:    1854
 * Dislikes: 148
 * Total Accepted:    177.4K
 * Total Submissions: 454.2K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> genSubTrees(int start, int end){
      vector<TreeNode*> res;
      if(start>end){
        return {NULL};
      }

      for(int i=start;i<=end;i++){
        vector<TreeNode*> left=genSubTrees(start, i-1);
        vector<TreeNode*> right=genSubTrees(i+1,end);
        for(int x=0;x<left.size();x++){
          for(int y=0;y<right.size();y++){
            TreeNode* root=new TreeNode(i);
            root->left=left[x];
            root->right=right[y];
            res.push_back(root);
          }
        }
      }
      return res;
    }

    vector<TreeNode*> generateTrees(int n) {
      vector<TreeNode*> res;
      if(n==0){
        return res;
      }
      
      res = genSubTrees(1,n);

      return res;
    }
};
// @lc code=end
