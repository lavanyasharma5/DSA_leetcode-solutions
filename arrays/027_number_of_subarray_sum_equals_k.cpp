/*
Problem: Subarray Sum Equals K (LeetCode)

Description:
Given an array of integers nums and an integer k, return the total number of
continuous subarrays whose sum equals k.

Approach:
- Use Prefix Sum + Hash Map
- Keep track of cumulative sum (prefix sum)
- If (current_sum - k) exists in the map, it means a subarray with sum k exists
- Store frequency of prefix sums in a map

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int subarraySum(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int, int> mpp; // Map to store the frequency of prefix sums
        mpp[0]=1; // Base case: there's one way to have a prefix sum of 0 (by taking no elements)
        int presum=0; // Variable to store the current prefix sum
        int count=0; // Variable to count the number of subarrays that sum to k


        for(int i=0; i<n; i++){
            presum += nums[i];
            int remove = presum - k;
            count += mpp[remove]; // If remove exists in the map, it means there's a prefix sum that we can remove to get k
            mpp[presum]++; // Increment the frequency of the current prefix sum
        }
        return count; // Return the total count of subarrays that sum to k
    }
};