/*
problem: 2562. Find the Maximum Total Value of Subarrays With Length K
link: https://leetcode.com/problems/find-the-maximum-total-value-of-subarrays-with-length-k/
difficulty: Medium

Description:
You are given a 0-indexed integer array nums and an integer k. 
The total value of a subarray is the difference between the maximum and minimum elements in the subarray. 
Return the maximum total value of all subarrays of nums with length k.
You can use the same subarray of nums multiple times in the calculation.

Approach:
1. Initialize two variables, maxi and mini, to store the maximum and minimum elements in the array, respectively.
2. Iterate through the input array nums to find the maximum and minimum elements.
3. The maximum total value of the subarray is the difference between the maximum and minimum elements
    multiplied by k, since we can use the same subarray multiple times in the calculation.
4. Return the calculated maximum total value as the final result.

Time Complexity: O(n), where n is the length of the input array nums.
Space Complexity: O(1), we are using only a constant amount of extra space to store
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    long long maxTotalValue(vector<int>& nums, int k){
        int maxi= INT_MIN;
        int mini= INT_MAX;

        for(int num: nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        // The maximum total value of the subarray is the difference between the maximum and minimum elements multiplied by k
        return (long long)(maxi - mini) * k;
    }
};