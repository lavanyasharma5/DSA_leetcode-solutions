/*
Problem: Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Difficulty: Medium

Idea:
Rotate array to the right by k steps.

Steps:
1. Reverse entire array
2. Reverse first k elements
3. Reverse remaining n-k elements

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotateRight(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n; // Handle cases where k is greater than n

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Step 3: Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};

/*
if we want to rotate left by k steps,
just reverse the steps:
1. reverse first k elements
2. reverse rest n-k elements
3. reverse all
*/