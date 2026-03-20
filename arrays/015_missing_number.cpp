/*
Problem: Missing Number
Link: https://leetcode.com/problems/missing-number/
Difficulty: Easy

Approach 1: Sum Formula
Sum of numbers from 0 to n = n(n+1)/2
Subtract sum of array from total sum.
Remaining value is missing number.

Approach 2: XOR Method
XOR of same numbers cancels out.
XOR all numbers from 0..n and XOR all array elements.
Remaining value is missing number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    //Using sum formula
    int missingNumberSum(vector<int>& nums) {
        int n=nums.size();
        int total_sum = n * (n + 1) / 2; // Sum of first n natural numbers
        int array_sum = 0;

        for(int num : nums){
            array_sum += num; // Calculate the sum of elements in the array
        }

        return total_sum - array_sum; // The missing number is the difference
        
    }

    //Using XOR
    int missingNumberXor(vector<int>& nums) {
        int n = nums.size();
        int xor1 = n; // XOR of all numbers from 0 to n
        int xor2 = 0; // XOR of all elements in the array

        for(int i=0; i<n; i++){
            xor1 ^= i; // XOR with numbers from 0 to n-1
            xor2 ^= nums[i]; // XOR with elements in the array
        }

        return xor1 ^ xor2; // The missing number is the XOR of these two results
    }
    
};

