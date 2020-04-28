/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (46.19%)
 * Likes:    2802
 * Dislikes: 80
 * Total Accepted:    320.6K
 * Total Submissions: 689.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* subTree(vector<int>& preorder, int& index, vector<int>& inorder, int start, int end){
      if(start>end){
        return NULL;
      }else{
        int i=0;
        TreeNode* root=new TreeNode(preorder[index]);
        for(i=start;i<inorder.size();i++){
          if(preorder[index]==inorder[i]) break;
        }
        //cout<<"Node:"<<preorder[index]<<", start:"<<start<<", i:"<<i<<", end:"<<end<<" \n";
        index++;
        TreeNode* leftTree=subTree(preorder, index, inorder, start, i-1);
        TreeNode* rightTree=subTree(preorder, index, inorder, i+1, end);
        root->left=leftTree;
        root->right=rightTree;
        return root;
      }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int index=0;
      return subTree(preorder, index, inorder, 0, preorder.size()-1);
    }
};
// @lc code=end
