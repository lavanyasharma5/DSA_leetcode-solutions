/*
Problem: Find First and Last Position of Element in Sorted Array (LeetCode)

Description:
Given a sorted array nums, find the starting and ending position of a given target value.
If target is not found, return [-1, -1].

Approach:
- Use Binary Search twice:
  1. First occurrence → move left when found
  2. Last occurrence → move right when found
- Keep updating answer while searching

{ This problem = combination of:
👉 Lower Bound (first ≥ target)
👉 Upper Bound (first > target) }

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        //initially set first and last to -1 (not found)
        int first = -1, last =-1;

        //for first occurrence
        while(low<=high){
            int mid = low + (high - low)/2;
            if(target == nums[mid]){
                first= mid; //update first occurrence
                high= mid-1; //move left to find earlier occurrence
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        //reset low and high for another binary search
        low =0, high = n-1;

        //for last occurence
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == nums[mid]){
                last = mid; //update last occurrence
                low = mid +1; //move right to find later occurrence
            }
            else if( target < nums[mid]){
                high = mid -1;           
            }
            else{
                low = mid +1;
            }
        }        
        return {first, last}; //return the first and last occurrence
    }
};