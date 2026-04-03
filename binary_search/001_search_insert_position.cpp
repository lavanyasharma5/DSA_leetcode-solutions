/*
Problem: Search Insert Position
link: https://leetcode.com/problems/search-insert-position/
Difficulty: Easy

Description:
Given a sorted array of distinct integers and a target value,
return the index if the target is found.
If not, return the index where it would be inserted in order.

Approach:
- Use Binary Search to efficiently find the position.
- If target <= nums[mid], store mid as a potential answer and search left.
- Otherwise, search right.
- The variable 'ans' keeps track of the correct insert position.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution{
    public:
    int searchInsert(vector<int>& nums, int target){
        int n= nums.size();
        int low=0, high=n-1;

        // Initialize ans to n, which is the position if target is greater than all elements
        int ans=n;

        while(low<=high){
            int mid= low + (high-low)/2;

            if(nums[mid] <= target){
                ans= mid; // Update ans to mid, as this is a potential insert position
                high=mid-1; // Search in the left half to find a smaller index if target is found
            }
            else{
                low= mid+1;; // Search in the right half
            }
        }
        return ans;
    }
};