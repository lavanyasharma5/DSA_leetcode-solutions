/*
problem: Split Array Largest Sum
link: https://leetcode.com/problems/split-array-largest-sum/
difficulty: hard

Description:
Given an array which consists of non-negative integers and an integer m
you can split the array into m non-empty subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Approach:
- Use Binary Search to find the minimum largest sum.
- The minimum largest sum can be at least the maximum element in the array 
(since we can't split an element) and at most the sum of all elements (if we don't split at all).
- For each candidate largest sum, check if it's possible to split the array into m 
or fewer subarrays without exceeding the candidate largest sum.
- If it's possible, we can try a smaller largest sum; otherwise, we need to try a larger one.

Time Complexity: O(n * log(sum of array))
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long limit){
        int subarrays = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            // need new subarray
            if(sum + nums[i] > limit){
                subarrays++;
                sum = nums[i]; // start new subarray with current element
            }
            else{
                sum += nums[i];
            }
        }
        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low <= high){
            long long mid = (low + high) / 2;
            //mid becomes the candidate largest sum, check if we can split the array into m subarrays with this limit
            if(canSplit(nums, k, mid)){
                // try smaller answer
                high = mid - 1;
            }
            else{
                // need bigger answer
                low = mid + 1;
            }
        }
        return low;
    }
};