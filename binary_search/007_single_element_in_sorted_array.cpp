/*
Problem: Single Element in a Sorted Array 
link: https://leetcode.com/problems/single-element-in-a-sorted-array/
difficulty: Medium

Description:
Given a sorted array where every element appears twice except one,
find the single element.

Approach:
- Use Binary Search
- Observe index pattern:
    - Before single element → pairs start at even index
    - After single element → pattern breaks and first element of pair starts at the odd index
- Check mid:
    - If part of correct pattern → move right
    - Else → move left

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution{
    public:
    int singleNonDuplicate(vector<int>& nums){
        int n= nums.size();

        // Edge case: If array has only one element, return that element
        if(n==1) return nums[0];

        //to check if the single element is at the beginning or end of the array
        if(nums[0] != nums[1]) return nums[0];

        //to check if the last element is the single element
        if(nums[n-1] != nums[n-2]) return nums[n-1];


        // Binary Search between the second and second last element
        //as we have handled all the edge cases above only 
        int low= 1;
        int high= n-2; 

        while(low <= high){
            int mid = low + (high-low)/2;

            // Check if mid is the single element
            if(nums[mid-1] != nums[mid] && nums[mid != nums[mid+1]]){
                return nums[mid]; // Found the single element
            }

            if( (mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                // If mid is odd and matches the previous element
                //or mid is even and matches the next element
                //means the pattern is correct, so move right to find the single element
                low = mid+1;
            }
            else{
                // Pattern is broken, move left to find the single element
                high = mid-1;
            }
        }
        return -1; // This line should never be reached if input is valid
    }

};