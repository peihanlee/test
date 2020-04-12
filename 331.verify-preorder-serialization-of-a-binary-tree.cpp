/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (39.78%)
 * Likes:    674
 * Dislikes: 42
 * Total Accepted:    67.9K
 * Total Submissions: 170.6K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 * 
 * 
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * 
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 * 
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * 
 * 
 * Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: "1,#"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "9,#,#,1"
 * Output: false
 */

// @lc code=start
class Solution {
public:
    struct Node{
      int val;
      Node *left;
      Node *right;
      Node(int v): val(v), left(NULL), right(NULL){
      }
    };

    Node *isValidBinaryTree(string &str, int &pos, bool &valid){
      if(pos<str.size()){
        int nextComma = -1;
        string val_str;
        nextComma = str.find(',',pos);
        cout<<"next comma:"<<nextComma<<"\n";
        if(nextComma>0){
          val_str=str.substr(pos, nextComma-pos);
          pos = nextComma + 1;
        }else{
          val_str=str.substr(pos, str.size()-pos);
          pos = str.size();
        }
        if(val_str.size()>0){
          if(val_str[0] == '#'){
            return NULL;
          }else{
            Node *n = new Node(stoi(val_str));
            n->left = isValidBinaryTree(str, pos, valid);
            n->right = isValidBinaryTree(str, pos, valid);
            return n;
          }
        }else{
          valid = false;
          return NULL;
        }
      }else{
        valid = false;
        return NULL;
      }
    }

    bool isValidSerialization(string preorder) {
      bool valid = true;
      int next_pos = 0;
      isValidBinaryTree(preorder, next_pos, valid);
      if(next_pos<preorder.size()){
        valid = false;
      }
      cout<<"End next_pos:"<<next_pos<<"\n";
      return valid;
        
    }
};
// @lc code=end
