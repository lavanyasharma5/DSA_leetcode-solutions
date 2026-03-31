/*
Problem: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
Difficulty: Easy

Description:
Given an integer array nums, return true if any value appears at least twice,
and return false if every element is distinct.

Approach:
- Sort the array so that duplicate elements come next to each other.
- Traverse the array and compare each element with the previous one.
- If any two adjacent elements are equal, return true.

Time Complexity: O(n log n)  (due to sorting)
Space Complexity: O(1)      (no extra space used)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    bool containsDuplicate(vector<int>& nums){
        // Sort the array to bring duplicates together
        sort(nums.begin(), nums.end()); 

        for(int i=1; i<nums.size(); i++){
            // If the current element is the same as the previous one, we have found a duplicate
            if(nums[i] == nums[i-1]) return true;
        }
        // If we finish the loop without finding duplicates, return false
        return false;
    }
};
