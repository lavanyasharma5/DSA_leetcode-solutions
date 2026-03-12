/*
Problem: Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
Difficulty: Easy

Idea:
We merge two sorted arrays.

nums1 has extra space at the end.

We start from the back to avoid overwriting elements.

i -> last real element of nums1
j -> last element of nums2
k -> last position of nums1

Compare nums1[i] and nums2[j]
Put larger at nums1[k]

Time Complexity: O(m+n)
We traverse both arrays once.

Space Complexity: O(1)
We do not use extra space, we modify nums1.
*/

#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]= nums1[i--];
            }else{
                nums1[k--]= nums2[j--];
            }
        }
        // If there are remaining elements in nums2, copy them
        while(j>=0){
            nums1[k--]= nums2[j--];
        }       
    }
};