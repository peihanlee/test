/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.87%)
 * Likes:    3048
 * Dislikes: 156
 * Total Accepted:    416.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkNeighbor(int m, int n, int i, int j, vector<vector<char>>& board, int length, int pos, string word){
      if(board[i][j]==word[pos]){
        char temp;
        if(pos==(length-1)){
          return true;
        }

        //cout<<"i:"<<i<<", j:"<<j<<"\n";

        temp=board[i][j];
        board[i][j]='*';

        if(i>0 && checkNeighbor(m,n,i-1,j,board,length,pos+1,word)==true){
          return true;
        }
        if(i<m-1 && checkNeighbor(m,n,i+1,j,board,length,pos+1,word)==true){
          return true;
        }
        if(j>0 && checkNeighbor(m,n,i,j-1,board,length,pos+1,word)==true){
          return true;
        }
        if(j<n-1 && checkNeighbor(m,n,i,j+1,board,length,pos+1,word)==true){
          return true;
        }
        board[i][j]=temp;
      }
      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
      int m=board.size();
      int n=board[0].size();
      int length=word.size();
      int pos=0;
      
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(checkNeighbor(m,n,i,j,board,length,0,word)==true){
            return true;
          }
        }
      }

      return false;
        
    }
};
// @lc code=end
