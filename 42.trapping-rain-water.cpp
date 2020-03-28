/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
      int i;
      int total_trap=0;
      int size=height.size();
      vector<int> left_max(size);
      vector<int> right_max(size);

      if(size == 0)
      {
        return 0;
      }
 
      left_max[0]=height[0];
      for(i=1;i<size;i++){
        left_max[i] = max(left_max[i-1],height[i]); 
      }

      right_max[size-1]=height[size-1];
      for(i=size-2;i>=0;i--){
        right_max[i] = max(right_max[i+1],height[i]); 
      }

      for(i=1;i<size-1;i++)
      {
        total_trap += (min(left_max[i],right_max[i]) - height[i]);
      }
      return total_trap;        
    }
};
// @lc code=end
