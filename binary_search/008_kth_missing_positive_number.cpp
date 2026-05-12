/*
Problem: Kth Missing Positive Number
link: https://leetcode.com/problems/kth-missing-positive-number/
difficulty: Easy

Description:
Given an array arr of positive integers sorted in a strictly increasing orderand an integer k.
Return the kth missing positive integer from this array.

Approach:
- Use Binary Search to find the position where the kth missing number would fit in the array.
Calculated missing numbers till each index using:
missing = arr[i] - (i + 1)
Applied binary search to find the first index where the count of missing numbers becomes greater than or equal to k.
Finally returned:
answer = low + k

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    int findKthPositive(vector<int>& arr, int k){
        int low =0;
        int high= arr.size()-1;

        while(low <= high){
            int mid = (low+high)/2;
            int missing = arr[mid] - (mid + 1); // Calculate the number of missing numbers up to index mid

            if(missing < k){
                low = mid + 1; // Move to the right half
            }
            else{
                high = mid - 1; // Move to the left half
            }
        }
        return low + k;
    }
};
