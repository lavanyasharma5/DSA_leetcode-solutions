/*
Problem: Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Difficulty: Easy

Idea:
Use two pointers.

i → last unique element
j → scan array

If nums[j] is different,
move i forward and copy value.

Return i + 1.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; 
        
        int i = 0; // Pointer to track the position of the last unique element
        for (int j = 1; j < nums.size(); j++) {
            // If the current element is different from the last unique element, move the pointer and update the value
            if (nums[i] != nums[j]) {
                i++; // Move the pointer to the next position for a unique element
                nums[i] = nums[j]; // Update the position of the last unique element
            }
        }
        return i + 1; // The length of the array with unique elements is the index + 1
    }
};