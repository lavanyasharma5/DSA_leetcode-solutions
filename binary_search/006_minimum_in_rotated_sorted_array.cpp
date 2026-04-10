/*
Problem: Find Minimum in Rotated Sorted Array
link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
difficulty: Medium

Description:
Given a rotated sorted array with distinct elements,
find the minimum element.

Approach:
- Use Binary Search
- If current range is sorted → nums[low] is minimum
- Otherwise:
    - If left half is sorted → search right half
    - Else → search left half
- Keep track of minimum element

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    int findmin(vector<int>& nums){
        int n= nums.size();
        int low=0;
        int high= n-1;
        int mini= INT_MAX;

        while( low <= high){
            int mid= low + (high-low)/2;

            //the current range is sorted, so the minimum element is the smaller of the current minimum and the leftmost element
            if(nums[low] <= nums[high]){
                mini= min(mini, nums[low]);
                break; //since the current range is sorted, we can break out of the loop
            }

            //check if left half is sorted
            if(nums[low] <= nums[mid]){
                mini= min(mini, nums[low]);
                low= mid+1; //search in the right half
            }
            //right half is sorted
            else{
                mini= min(mini, nums[mid]);
                high= mid-1; //search in the left half
            }
        }
        return mini;
    }
};