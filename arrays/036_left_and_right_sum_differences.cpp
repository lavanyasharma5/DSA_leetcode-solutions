/*
Problem: 2574. Left and Right Sum Differences
Link: https://leetcode.com/problems/left-and-right-sum-differences/
Difficulty: Easy

Description:
You are given a 0-indexed integer array nums. 
The left sum of an index i is the sum of all elements to the left of i in the array. 
The right sum of an index i is the sum of all elements to the right of i in the array. 
The left-right difference of an index i is the absolute difference between the left sum and right sum of i.
Return an array of size n where the value at the ith index is the left-right difference for index i in the array.

Approach:
1. Compute the total sum of the array.
2. Maintain a variable leftSum to store the sum of elements to the left of the current index.
3. For each index, calculate rightSum = totalSum - leftSum - nums[i].
4. Store abs(leftSum - rightSum) in the answer array.
5. Update leftSum by adding nums[i].
6. Return the resulting array.

Time Complexity: O(n) where n is the length of the input array.
Space Complexity: O(n) for the output array.
*/

#include<vector>
#include<cmath>
using namespace std;

class Solution{
    public:
    vector<int> leftRightDifference(vector<int>& nums){
        int n= nums.size();

        int total=0;
        //calculate the total sum of the array
        for(int num: nums){
            total += num;
        }

        vector<int> ans;
        int left=0;

        for(int i=0; i<n; i++){
            //calculate the right sum by subtracting the left sum and the current element from the total sum
            int right= total - left - nums[i];

            //calculate the absolute difference and add it to the answer vector
            ans.push_back(abs(left - right));

            //update the left sum by adding the current element
            left += nums[i];
        }
        return ans;
    }
};