/*
problem: 2161. Partition Array According to Given Pivot
link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
difficulty: Medium

description:
Given an array of integers nums and an integer pivot, partition the array into three parts:
- The first part contains all elements less than pivot.
- The second part contains all elements equal to pivot.
- The third part contains all elements greater than pivot.
The relative order of the elements in each part should be the same as in the original array.
Return the partitioned array.

Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]

Approach:
1. Create an answer array of the same size as the input array to store the partitioned elements.
2. Use two pointers, left and right, to keep track of the positions where we will place the elements less than and greater than the pivot, respectively.
3. Iterate through the input array using two pointers, i from the start and j from the end:
    - If the current element at index i is less than the pivot, place it on the left side of the answer array and move the left pointer to the right.
    - If the current element at index j is greater than the pivot, place it on the right side of the answer array and move the right pointer to the left.
    - Move both pointers towards the center.
4. After the loop, fill the remaining elements in the answer array with the pivot value.
5. Return the answer array as the final result.

Time Complexity: O(n), where n is the length of the input array nums.
Space Complexity: O(n), ans array szie equal to the input array size.
*/

#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot){
        int n = nums.size();
        vector<int> ans(n);

        // We will use two pointers, left and right, to keep track of the positions 
        //where we will place the elements less than and greater than the pivot, respectively.
        int left =0, right = n-1;

        //two ptrs to iterate thru the nums array, i from the start and j from the end
        int i=0, j=n-1;

        while(i<n){
            if(nums[i] < pivot){
                //place the element on the left of the answer array and move the left pointer to the right
                ans[left++] = nums[i];
            }
            else if(nums[j] > pivot){
                //place the element on the right of the answer array and move the right pointer to the left
                ans[right--] = nums[j];
            }
            //move the pointers towards the center
            i++;
            j--;
        }
        //fill the remaining elements in the answer array with the pivot value
        while(left < right){
            ans[left++] = pivot;
        }

        return ans;
    }
};