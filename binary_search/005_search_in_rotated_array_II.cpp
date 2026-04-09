/*
Problem: Search in Rotated Sorted Array II 
link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
difficulty: Medium

Description:
Given a rotated sorted array nums that may contain duplicates,
return true if target exists, otherwise false.

Approach:
- Modified Binary Search
- If duplicates (low == mid == high), shrink both sides (edge case)
- Otherwise, identify sorted half and check if target lies in it

Time Complexity: O(log n) average, O(n/2) worst case (due to duplicates)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    bool search(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low <= high){
            int mid= low + (high-low)/2;

            //target found
            if(nums[mid] == target) return mid;

            //handle duplicates
            //edge case: low, mid, high are same so cant be sure which half is sorted, shrink both sides
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue; //skip the rest of the loop and start next iteration with updated low and high
            }
            
            //check if left half is sorted
            if(nums[low] <= nums[mid]){
                if( target >= nums[low] && target < nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            //right half is sorted
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
         }
        return false;
    }
};