/*
problem: Find Peak Element
link: https://leetcode.com/problems/find-peak-element/
difficulty: Medium

Description:
A peak element is an element that is strictly greater than its neighbors. 
Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks. 
You may imagine that nums[-1] = nums[n] = -∞.

Approach:
- We can use binary search to find a peak element.
- We check the middle element and compare it with its neighbors.
- If the middle element is greater than both neighbors, it is a peak, so we return its index.
- If the left neighbor is greater, a peak must exist in the left half, so we search left.
- Otherwise, a peak must exist in the right half, so we search right.
- We repeat this process until we find a peak element.

Time Complexity: O(log n) because we are halving the search space in each step
Space Complexity: O(1) 
*/

#include <vector>
using namespace std;

class Solution{
    public:
    int findPeakElement(vector<int>& nums){
        int n= nums.size();

        //if only one element in the array then that is the peak element
        if(n == 1) return 0;

        //check if the first element is a peak element
        if(nums[0] > nums[1]) return 0;

        //check if the last element is a peak element
        if(nums[n-1] > nums[n-2]) return n-1;
        
        //exclude the first and the last element from the search as we have already checked them
        int low=1, high=n-1; 

        while(low <= high){
            int mid= (low + high)/2;

            //check if the middle element is a peak element
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            //the left element is bigger so move left and eliminate the right half 
            //uphill move
            else if(nums[mid] < nums[mid-1]){
                high = mid-1;
            }
            //the right element is bigger so move right and eliminate the left half
            //downhill move
            else{
                low = mid+1;
            }
        }
        return -1; //this line will never be reached as there is always a peak element
    }

};

