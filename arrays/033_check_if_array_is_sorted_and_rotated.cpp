/*
problem: Check if Array Is Sorted and Rotated
link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
difficulty: Easy

Description:
Given an array of integers nums, return true if the array was originally sorted in non-decreasing
order, then rotated some number of positions (including zero). Otherwise, return false.

Approach:
- Count the number of times an element is greater than the next element in the array
- If the count is more than 1, it means the array is not sorted and rotated
- If the count is 0 or 1, it means the array is sorted and rotated

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    bool check(vector<int>& nums){
        int n= nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            //compare current element with the next element (circularly)
            if(nums[i] > nums[(i+1)%n]) count++; //if current element is greater than the next element, it means there is a rotation point
        }
        return count <= 1; //if count is more than 1, it means the array is not sorted and rotated
    }
};
