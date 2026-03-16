/*
Problem: Next Permutation
link: https://leetcode.com/problems/next-permutation/
difficulty: Medium

Idea:
Find first decreasing element from right.
Swap with next greater element.
Reverse the right side.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums){
            int n=nums.size();
            int ind=-1; // index of the first decreasing element from the right

            // find the first decreasing element from the right
            for(int i=n-2; i>=0; i--){
                if(nums[i]<nums[i+1]){
                    ind= i;
                    break;
                }
            }
            // if no such element is found, reverse the array and return
            if(ind==-1){
                reverse(nums.begin(), nums.end());
                return;
            }

            // find the first element from the right that is greater than nums[ind] and swap them
            for(int i=n-1; i>ind; i++){
                if(nums[i]>nums[ind]){
                    swap(nums[i], nums[ind]); 
                    break;
                }
            }

            // reverse the subarray to the right of ind
            reverse(nums.begin()+ind+1, nums.end());     
        }
        
};