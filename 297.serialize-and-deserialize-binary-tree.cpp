/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (45.44%)
 * Likes:    2536
 * Dislikes: 125
 * Total Accepted:    281K
 * Total Submissions: 617.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
public:
    void encStr(TreeNode* node, string &str){
      if(node!=NULL){
        str.append(to_string(node->val));
        str.append(" ");
        encStr(node->left, str);
        encStr(node->right, str);
      } else {
        str.append("# ");
      }
      
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string res;
      encStr(root,res);
      return res;
    }

    string searchValue(string str, int &i){
      int start_i=i;
      string res_str;
      while(i<str.size()){
        if(str[i]==' '){
          res_str = str.substr(start_i,i-start_i);
          i++;
          return res_str;
        }
        i++;
      }
      return "#";
    }

    TreeNode *decStr(string data, int &i){
      TreeNode *node = NULL;
      string res_str;
      res_str = searchValue(data, i);
      if(res_str[0]!='#'){
        node = new TreeNode(stoi(res_str));
        node->left=decStr(data,i);
        node->right=decStr(data,i);
        return node;
      }else{
        return NULL;
      }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      TreeNode *node = NULL;
      int i=0;
      cout<<"["<<data<<"]\n";
      node = decStr(data,i);
      return node;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
