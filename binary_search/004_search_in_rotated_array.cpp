/*
Problem: Search in Rotated Sorted Array 
link: https://leetcode.com/problems/search-in-rotated-sorted-array/
difficulty: Medium

Description:
Given a rotated sorted array nums (with distinct integers) and a target value,
return its index if found, otherwise return -1.

A rotated sorted array means the array was originally sorted,
but then rotated at some pivot.

Approach:
- Use modified Binary Search
- At every step, one half (left or right) is always sorted
- Check which half is sorted:
    1. If left half is sorted:
        - Check if target lies in [low, mid)
        - If yes → search left
        - Else → search right
    2. If right half is sorted:
        - Check if target lies in (mid, high]
        - If yes → search right
        - Else → search left

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution{
    int search(vector<int>& nums, int target){
        int n= nums.size();
        int low=0;
        int high= n-1;

        while(low <= high){
            int mid= low + (high-low)/2;

            //target found 
            if(nums[mid] == target) return mid;

            //check if left half is sorted
            if(nums[low] <= nums[mid]){
                //target lies in left half
                if(target >= nums[low] && target < nums[mid]){
                    high= mid-1;
                }
                //target lies in right half
                else{
                    low= mid+1;
                }
            }
            //right half is sorted
            else{
                //target lies in right half
                if(target > nums[mid] && target <= nums[high]){
                    low= mid+1;
                }
                //target lies in left half
                else{
                    high= mid-1;
                }
            }
        }
        return -1; //target not found
    }
};