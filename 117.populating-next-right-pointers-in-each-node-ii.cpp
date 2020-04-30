/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (37.35%)
 * Likes:    1341
 * Dislikes: 169
 * Total Accepted:    233.1K
 * Total Submissions: 620.4K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if(!root) return NULL;
      Node* cur=root;
      Node dummy(0);
      Node* pre=&dummy;

      while(cur){
        if(cur->left){
          pre->next=cur->left;
          pre=pre->next;
        }
        if(cur->right){
          pre->next=cur->right;
          pre=pre->next;
        }
        cur=cur->next;
      }
      connect(dummy.next);

      return root;
    }
};
// @lc code=end
