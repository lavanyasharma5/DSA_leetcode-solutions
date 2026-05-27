/*
problem: Median of Two Sorted Arrays
link: https://leetcode.com/problems/median-of-two-sorted-arrays/
difficulty: Hard

Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

Approach:
- We can use binary search to find the correct partition of the two arrays
- We will partition the two arrays such that the left half of the combined array is less than the right half
- We will compare the elements at the partition to check if we have found the correct partition
- If we have found the correct partition, we can calculate the median based on the total number of elements in the combined array

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();

        //make sure nums1 is the smaller array
        if(n>m) return findMedianSortedArrays(nums2, nums1); 

        int low=0, high=n; //we can take 0 to n elements from nums1
        int left = (n + m + 1) / 2; //total elements

        while(low <= high){
            //how many elements we take from nums1
            int mid1 = (low + high) >> 1;
            //remaining elements taken from nums2
            int mid2 = left - mid1;

            //left side
            int l1 = INT_MIN, l2 = INT_MIN;
            //right side
            int r1 = INT_MAX, r2 = INT_MAX;

            //checking boundaries
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];

            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            //correct partition allowed
            if(l1 <= r2 && l2 <= r1){
                // odd total elements
                if((n + m) % 2 == 1) {
                    return max(l1, l2);
                }
                // even total elements
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            // too many elements taken from nums1
            else if(l1 > r2) {
                high = mid1 - 1;
            }
            // too few elements taken from nums1
            else {
                low = mid1 + 1;
            } 
        }
        return 0.0;
    }
};