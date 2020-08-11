/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (34.45%)
 * Likes:    1441
 * Dislikes: 76
 * Total Accepted:    162K
 * Total Submissions: 465.5K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */

// @lc code=start
class WordDictionary {
public:
    #if 0
    class Node{
      public:
        Node *next[26];
        bool hasNext;
        bool isWord;
        Node(){
          isWord=false;
          for(int i=0;i<26;i++){
            next[i]=NULL;
          }
        }
    };
    #else
    struct Node{
        struct Node *next[26];
        bool hasNext;
        bool isWord;
        Node(){
          isWord=false;
          for(int i=0;i<26;i++){
            next[i]=NULL;
          }
        }
    };
    #endif
    Node *root = NULL;

    /** Initialize your data structure here. */
    WordDictionary() {
      //Node *root=new Node();
      root=new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
      Node *cur=root;
      int size=word.size();
      if(size==0) return;
      //cout<<"\n*************** add:["<<word<<"]\n";
      for(int i=0; i<size;i++){
        if(cur->next[word[i]-'a'] == NULL){
          cur->next[word[i]-'a'] = new Node();
        }
        cur=cur->next[word[i]-'a'];
        //cout<<"addr:"<<cur<<"\n";
      }
      cur->isWord=true;        
    }
    
    bool searchSubstring(Node *cur, string word){
      int size=word.size();
      for(int i=0; i<size;i++){
        if(word[i]=='.'){
          //cout<<"found '.'\n";
          //if(i==size-1){
          //  for(int j=0;j<26;j++){
          //    if(cur->next[j]!=NULL){
          //      return true;
          //    }
          //  }
            //return cur->isWord;
          //}else {
            for(int j=0;j<26;j++){
              if(cur->next[j]!=NULL){
                if(searchSubstring(cur->next[j],word.substr(i+1,size-i-1))){
                  return true;
                }
              }
            }
            return false;
          //}
        }else if(cur->next[word[i]-'a']!=NULL){
          //cout<<"found '"<<word[i]<<"'\n";
          //if(i==size-1){
          //  cout<<"return:"<<cur->isWord<<"\n";
          //  return cur->next[word[i]-'a']->isWord;
          //}else{
          cur=cur->next[word[i]-'a'];
          //cout<<"addr:"<<cur<<"\n";
          //}
        }else{
          //cout<<"No found\n";
          return false;
        }
      }        
      //return false;
      //cout<<"End return:"<<cur->isWord<<"\n";
      return cur->isWord;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      Node *cur=root;
      int size=word.size();
      if(size==0) return false;
      //cout<<"\n*************** search:["<<word<<"]\n";
      return searchSubstring(cur, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
