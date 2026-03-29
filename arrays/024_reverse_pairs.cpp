/*
Problem: Reverse Pairs 
Link: https://leetcode.com/problems/reverse-pairs/
Difficulty: Hard

Description:
Given an array nums, return the number of reverse pairs.
A reverse pair is defined as:
i < j AND nums[i] > 2 * nums[j]

Approach:
We use a modified Merge Sort.
While merging, we count valid reverse pairs using two pointers.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<vector>
using namespace std;

class Solution{
    public:

    int countPairs(vector<int>& nums, int low, int mid, int high){
        int count=0;
        int right=mid+1; // Pointer for the right half to count valid pairs

        // For each element in the left half, move the right pointer to find valid pairs
        for(int i= low; i<= mid; i++){
            // Move the right pointer until we find an element that does not satisfy the reverse pair condition
            while(right <= high && (long)nums[i] > 2 * (long)nums[right]){
                right++;

            }
            count += (right - (mid + 1)); // Count valid pairs for the current element
        }    
        return count;            
    }

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp; // Temporary array to hold merged elements
        int left= low, right= mid+1;

        // Merge the two halves while maintaining sorted order
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        // If there are remaining elements in the left half, add them to temp
        while(left <= mid){
            temp.push_back(nums[left++]);
        }

        // If there are remaining elements in the right half, add them to temp
        while(right <= high){
            temp.push_back(nums[right++]);
        }

        // Copy the merged elements back into the original array
        for(int i= low; i<= high; i++){
            nums[i] = temp[i - low];
        }
    }

    int mergeSort(vector<int>& nums, int low, int high){
        // Base case: if the subarray has one or no elements, there are no reverse pairs
        if(low >= high) return 0; 

        int mid = (low+high)/2;
        int count=0;

        // Recursively count reverse pairs in the left and right halves
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        // Count reverse pairs across the two halves
        count += countPairs(nums, low, mid, high);
        // Merge the two halves
        merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums){
        return mergeSort(nums, 0, nums.size()-1);
    }
};