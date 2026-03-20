/*
Problem: Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/
Difficulty: Easy

Idea:
Traverse the array and count consecutive 1s.
If current element is 1 → increase count.
If 0 appears → reset count.
Keep track of maximum count.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int maxi=0;
        int count1=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count1++; // Increment count of consecutive 1s
                maxi=max(maxi, count1); // Update maximum count of consecutive 1s
            }else{
                count1=0; // Reset count when a 0 is encountered
            }
        }
        return maxi; // Return the maximum count of consecutive 1s
    }

};