/*
Problem: 4Sum
Link: https://leetcode.com/problems/4sum/
Difficulty: Medium

Idea:
Sort the array.
Fix two elements (i, j).
Use two pointers (k, l) to find remaining two.

Move pointers based on sum.
Skip duplicates.

Time Complexity: O(n^3)
Space Complexity: O(1) extra
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort the array to use two pointers and skip duplicates

        // Fix the first two elements
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if( (j != i+1) && nums[j]==nums[j-1]) continue;

                int k=j+1; // left pointer
                int l=n-1;// right pointer, from the end

                while(k<l){
                    long long sum= nums[i];
                    sum+= nums[j];
                    sum+= nums[k];
                    sum+= nums[l]; // Use long long to avoid integer overflow

                    if(sum>target){
                        l--; // We need a smaller sum, move the right pointer to the left
                    }
                    else if(sum<target){
                        k++; // We need a larger sum, move the left pointer to the right
                    }
                    else{
                        vector<int> temp= {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp); // Found a quadruplet
                        k++;
                        l--;
                        // Skip duplicates for k and l
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && l<n-1 && nums[l]==nums[l+1]) l--;
                    }
                }

            }
        }
        return ans;
    }
};