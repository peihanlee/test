/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (32.34%)
 * Likes:    1889
 * Dislikes: 91
 * Total Accepted:    170.7K
 * Total Submissions: 527.5K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct Node{
      struct Node *next[26];
      string str;
      Node():str(""){
        for(int i=0;i<26;i++){
          next[i]=NULL;
        }
      }
    };

    void searchWord(vector<vector<char>>& board, int x, int y, int n, int m, vector<vector<bool>>& visit, struct Node *root, vector<string>& res){
      if(visit[m][n]==true || root->next[board[m][n]-'a']==NULL){
        return;
      }else{
        cout<<"("<<n<<","<<m<<"):"<<board[m][n]<<"\n";
      }

      visit[m][n]=true;
      root=root->next[board[m][n]-'a'];
      
      if(!(root->str.empty())){
        res.push_back(root->str);
        root->str.clear();
      }

      if(m-1>=0){
        searchWord(board, x, y, n, m-1, visit, root, res);
      }
      if(m+1<y){
        searchWord(board, x, y, n, m+1, visit, root, res);
      }
      if(n-1>=0){
        searchWord(board, x, y, n-1, m, visit, root, res);
      }
      if(n+1<x){
        searchWord(board, x, y, n+1, m, visit, root, res); 
      }
      visit[m][n]=false;
      //cout<<"T0\n";
    }

    void search(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visit, struct Node *root, vector<string>& res){
      for(int m=0; m<y ; m++) {
        for(int n=0;n<x;n++) {
          //cout<<"Start *** ("<<n<<","<<m<<") ***\n";
          searchWord(board, x, y, n, m, visit, root, res);
        }
      }
    }

    void insert(vector<string>& words, struct Node *root){
      struct Node *cur=NULL;
      int total=words.size();
      for(int i=0;i<total;i++){
        cur = root;
        for(int j=0;j<words[i].size();j++){
          if(cur->next[words[i][j]-'a']==NULL){
            cur->next[words[i][j]-'a']=new Node();
          }
          cur=cur->next[words[i][j]-'a'];
        }
        cur->str=words[i];
      }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      struct Node *root = new Node();
      vector<string> res;
      int y=board.size();
      int x=board[0].size();
      vector<vector<bool>> visit(y, vector<bool>(x,false));

      if(!x || !y || !words.size()) return res;

      insert(words, root);
      search(board, x, y, visit, root, res);

      return res;
    }
};
// @lc code=end
