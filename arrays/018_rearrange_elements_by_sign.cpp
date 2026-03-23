/*
Problem: Rearrange Array Elements by Sign
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
Difficulty: Medium

Idea:
We need to place positive numbers at even indices
and negative numbers at odd indices.

Use two pointers:
pos -> even index
neg -> odd index

Traverse array once and place elements accordingly.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution{
    public:
    vector<int> rearrangeArray(vector<int>& nums){
        int n=nums.size();
        //we create a new array of the same size to store the rearranged elements.
        vector<int> ans(n,0);

        int pos=0; //the index for the next positive number in the ans array
        int neg=1; //the index for the next negative number in the ans array

        /* the positive numbers are placed at even indices (0, 2, 4, ...) 
        and the negative numbers are placed at odd indices (1, 3, 5, ...). 
        We iterate through the input array and place each element
        in the correct position in the ans array based on its sign. */

        for(int i=0; i<n; i++){
            if(nums[i]>0){
                ans[neg]=nums[i];
                neg += 2; //move to the next odd index for the next negative number
            }else{
                ans[pos]=nums[i];
                pos += 2; //move to the next even index for the next positive number
            }
        }
        return ans; //return the rearranged array
    }
};