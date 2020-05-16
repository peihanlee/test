/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (34.97%)
 * Likes:    868
 * Dislikes: 436
 * Total Accepted:    211.2K
 * Total Submissions: 600.9K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      int sum=0;
      int a,b;

      for(int i=0;i<tokens.size();i++)
      {
        if(tokens[i].size()==1){
          switch(tokens[i][0]){
            case '+':
              b = st.top(); st.pop();
              a = st.top(); st.pop();
              sum = a+b;
              st.push(sum);
              break;
            case '-':
              b = st.top(); st.pop();
              a = st.top(); st.pop();
              sum = a-b;
              st.push(sum);
              break;
            case '*':
              b = st.top(); st.pop();
              a = st.top(); st.pop();
              sum = a*b;
              st.push(sum);
              break;
            case '/':
              b = st.top(); st.pop();
              a = st.top(); st.pop();
              sum = a/b;
              st.push(sum);
              break;
            default:
              sum=tokens[i][0]-'0';
              st.push(sum);
          }
        }else{
          sum=stoi(tokens[i],NULL,0);
          st.push(sum);
        }
        cout<<"push:"<<sum<<"\n";
      }
      sum=st.top();
      st.pop();
      return sum;         
    }
};
// @lc code=end
