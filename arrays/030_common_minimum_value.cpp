/*
Problem: Minimum Common Value
Link: https://leetcode.com/problems/minimum-common-value/
Difficulty: Easy

Description:
Given two sorted arrays nums1 and nums2,
return the smallest integer common to both arrays.
If there is no common element, return -1.

Approach:
- Use two pointers i and j
- Compare nums1[i] and nums2[j]
- If equal -> return the value
- If nums1[i] < nums2[j] -> move i
- Else -> move j
- If traversal ends -> return -1

Why this works:
Since arrays are sorted,
the smaller value can never match later elements
in the other array, so we move that pointer forward.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution{
    public:
    int getCommon(vector<int>& nums1, vector<int>& nums2){
        int n= nums1.size();
        int m= nums2.size();

        int i=0, j=0;

        while(i<n && j<m){
            if(nums1[i] == nums2[j]){
                return nums1[i];
                //both the arrays are sorted so the first common element will obv be the minimum
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1; //no common
    }

};