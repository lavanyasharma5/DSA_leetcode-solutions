/*
Problem: 3Sum
Link: https://leetcode.com/problems/3sum/
Difficulty: Medium

Idea:
Sort the array.
Fix one element.
Use two pointers to find the other two.

i -> fixed
j -> left pointer
k -> right pointer

Move j or k based on sum.

Avoid duplicates.

Time Complexity: O(n^2)
Space Complexity: O(1) extra
*/

#include<vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());


        // Fix the first element
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1; // left pointer
            int k=n-1;// right pointer, from the end

            // Move j and k towards each other
            while(j<k){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++; // We need a larger sum, move the left pointer to the right
                }
                else if(sum>0){
                    k--; // We need a smaller sum, move the right pointer to the left
                }
                else{
                    vector<int> temp= {nums[i], nums[j], nums[k]};
                    ans.push_back(temp); // Found a triplet
                    j++;
                    k--;

                    // Skip duplicates for j and k
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && k<n-1 && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return ans;
    }

};
