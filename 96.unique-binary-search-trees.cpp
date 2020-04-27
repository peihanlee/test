/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (49.97%)
 * Likes:    2724
 * Dislikes: 103
 * Total Accepted:    260.1K
 * Total Submissions: 518.4K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
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
class Solution {
public:
    int numTrees(int n) {
      vector<int> f(n+1,0);
      f[0] = 1;
      f[1] = 1;
      for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
          f[i]+=(f[j]*f[i-j-1]);
        }
        cout<<"->"<<n<<":"<<f[n]<<"\n";
      }

      return f[n];
    }
};
// @lc code=end
