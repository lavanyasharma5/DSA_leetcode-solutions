/*
Problem: Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/
Difficulty: Medium

Idea:
Use Kadane's Algorithm.

Keep running sum.
If sum becomes negative, reset.
Track maximum sum.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;

        for(int i=0; i<n; i++){
            sum += nums[i];
            maxi= max(sum, maxi);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};