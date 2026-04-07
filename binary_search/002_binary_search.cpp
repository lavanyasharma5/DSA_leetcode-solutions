/*
Problem: Binary Search
link: https://leetcode.com/problems/binary-search/
difficulty: Easy

Description:
Given a sorted array of integers and a target value,
return the index of the target if found.
Otherwise, return -1.

Approach:
- Use Binary Search
- Compare target with middle element
- If equal → return index
- If smaller → search left half
- If larger → search right half

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class solution{
    public:
    int binarySearch(vector<int>& nums, int target){
        int n=nums.size();
        int low= 0; // low is the starting index of the search range
        int high= n-1; // high is the ending index of the search range

        // We continue the search until low is less than or equal to high
        while(low <= high){
            // To avoid potential overflow, we calculate the mid index using this formula
            int mid = low + (high-low)/2; 

            // Check if the target is present at mid
            if(target == nums[mid]){
                return mid;
            }
            // If target is less than mid, then it can only be present in the left subarray
            else if(target < nums[mid]){
                high = mid-1;
            }
            // If target is greater than mid, then it can only be present in the right subarray
            else {
                low = mid+1;
            }
        }
        return -1; // If we reach here, it means the target was not found in the array
    }
};