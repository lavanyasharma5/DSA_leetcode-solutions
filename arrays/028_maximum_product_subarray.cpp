/*
Problem: Maximum Product Subarray 
link: https://leetcode.com/problems/maximum-product-subarray/
Difficulty: Medium

Description:
Given an integer array nums, find a contiguous subarray that has the largest product,
and return the product.

Approach:
- Traverse from left (prefix) and right (suffix)
- Keep multiplying elements
- Reset product to 1 when it becomes 0
- Track maximum product at each step

Key Insight:
Negative numbers can flip sign, so we check both directions

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution{
    public:
    int maxProduct(vector<int>& nums){
        int n=nums.size();
        int pre=1; // Prefix product
        int suf=1; // Suffix product
        int ans= INT_MIN;

        for(int i=0; i<n; i++){
            // Reset prefix and suffix products to 1 if they become 0
            if(pre==0) pre=1;
            if(suf==0) suf=1;

            // Update prefix from the left
            pre *= nums[i];
            // Update suffix from the right
            suf *= nums[n-1-i];
            // Update the answer with the maximum of current prefix and suffix products
            ans= max(ans, max(pre, suf));   
        }
        return ans;
    }
};

