/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int total_size = 0;;
      int current = 0;
      int previos = 0;
      int i;
      int n1_position =0;
      int n2_position =0;
      double ret = 0.0;
      
      total_size=nums1.size()+nums2.size();

      for(i=0;i<=total_size/2;i++){
        previos = current;
        if(n2_position>=nums2.size() || (n1_position<nums1.size() && nums1[n1_position]<nums2[n2_position]))
        {
          current = nums1[n1_position];
          n1_position++;
        } 
        else
        {
          current = nums2[n2_position];
          n2_position++;
        }
      }

      if(total_size%2==0){
        ret =  ((double)previos+(double)current)/2;
      } else {
        ret = current;
      }
      cout<<ret;
      return ret;
    }
};
// @lc code=end
