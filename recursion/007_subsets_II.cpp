/*
    Problem: 90. Subsets II
    Link: https://leetcode.com/problems/subsets-ii/
    Difficulty: Medium

    Description:
    Given an integer array that may contain duplicate elements,
    return all possible unique subsets (the power set). The solution
    must not contain duplicate subsets.

    Approach:
    1. Sort the array so that duplicate elements become adjacent.
    2. Use backtracking to generate all possible subsets.
    3. At every recursive call:
           - Store the current subset in the answer.
           - Iterate through all remaining elements using a for loop.
    4. Skip duplicate elements at the same recursion level using:
           if(i > index && nums[i] == nums[i-1]) continue;
    5. Choose the current element, recurse with the next index,
       then backtrack by removing the last element.

    Why it works:
    - Sorting places duplicate elements next to each other.
    - Skipping duplicates at the same recursion level prevents
      identical subsets from being generated multiple times.
    - Every valid subset is generated exactly once.
    - Backtracking restores the previous subset after exploring
      each recursive branch.

    Time: O(2^N * N)
          - There are 2^N possible subsets.
          - Copying each subset into the answer can take O(N).

    Space: O(N) Recursive Stack
           (Excluding the output vector)
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        //store every subset
        ans.push_back(curr);

        //try every possible next element while avoiding duplicates
        for(int i= index; i<nums.size(); i++){
            if(i>index && nums[i] == nums[i-1]) continue;

            //choose the current element
            curr.push_back(nums[i]);

            //move to the next index
            solve(i + 1, nums, curr, ans);

            //Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //sort to put all duplicates together 
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, curr, ans);

        return ans;
    }
};