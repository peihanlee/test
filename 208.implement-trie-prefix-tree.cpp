/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (44.37%)
 * Likes:    2469
 * Dislikes: 44
 * Total Accepted:    249.8K
 * Total Submissions: 562.6K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

// @lc code=start
class Trie {
public:
    struct node{
      struct node *val[27];
      node(){
        for(int x=0;x<27;x++){
          val[x] = NULL;
        }
      }
    };
    /** Initialize your data structure here. */
    struct node *root=NULL;
    Trie() {
      root = new node();              
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      int n=word.size();
      struct node *tmpNode = root;
     
      for(int i=0;i<n;i++){
        if(tmpNode->val[word[i]-'a']==NULL){
          tmpNode->val[word[i]-'a']=new node();
        }
        tmpNode = tmpNode->val[word[i]-'a'];
      }
      tmpNode->val[26]=tmpNode;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      int n=word.size();
      struct node *tmpNode = root;
     
      for(int i=0;i<n;i++){
        if(tmpNode->val[word[i]-'a']==NULL){
          return false;
        }
        tmpNode = tmpNode->val[word[i]-'a'];
      }

      if(tmpNode->val[26]!=NULL)
        return true;
      else
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      int n=prefix.size();
      struct node *tmpNode = root;
     
      for(int i=0;i<n;i++){
        if(tmpNode->val[prefix[i]-'a']==NULL){
          return false;
        }
        tmpNode = tmpNode->val[prefix[i]-'a'];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
