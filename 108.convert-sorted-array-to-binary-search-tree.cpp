/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.59%)
 * Likes:    1982
 * Dislikes: 189
 * Total Accepted:    367.3K
 * Total Submissions: 656.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode* genBST(vector<int>& nums, int start, int end){
      if(start>end){
        return NULL;
      }else{
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        TreeNode *leftNode=genBST(nums,start,mid-1);
        TreeNode *rightNode=genBST(nums,mid+1,end);
        root->left=leftNode;
        root->right=rightNode;
        return root;
      }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return genBST(nums, 0, nums.size()-1);        
    }
};
// @lc code=end
