/*
Problem: Remove Element
link: https://leetcode.com/problems/remove-element/
Difficulty: Easy

Description:
Given an integer array nums and an integer val, remove all occurrences of val in-place.
Return the number of elements in nums which are not equal to val.

Approach:
- Use two pointers:
  1. j → traverses the array
  2. i → keeps track of where to place the next valid element
- If nums[j] != val, copy it to nums[i] and increment i
- Ignore elements equal to val

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int removeElement(vector<int>& nums, int val){
        int n= nums.size();
        int i=0; // Pointer for the position of the next non-val element

        for(int j=0; j<n; j++){
            if(nums[j] != val){
                nums[i] = nums[j]; // Move non-val element to the front
                i++; // Increment the position pointer
            }
        }
        return i; // The new length of the array after removing val
    }
};