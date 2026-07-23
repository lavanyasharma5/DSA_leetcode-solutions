/*
    Problem: Subset Sums
    LeetCode (Similar): https://leetcode.com/problems/subsets/
    GFG: https://www.geeksforgeeks.org/problems/subset-sums2234/1

    Difficulty: Medium

    Description:
    Given an array of integers, generate the sum of every possible
    subset of the array and return all subset sums in sorted order.

    Approach:
    1. Use recursion to explore every possible subset.
    2. At each index, we have two choices:
           - Include the current element in the subset
             (add its value to the current sum).
           - Exclude the current element
             (keep the current sum unchanged).
    3. Once all elements have been processed, store the current sum.
    4. After generating all subset sums, sort the answer before
       returning it.

    Why it works:
    - Every element has exactly two choices: take or don't take.
    - Recursively exploring both choices generates all 2^N subsets.
    - Since only the running sum is maintained (an integer passed by
      value), backtracking is not required.

    Time: O(2^N + 2^N * log(2^N))
          - O(2^N) to generate all subset sums.
          - O(2^N * log(2^N)) to sort the resulting sums.

    Space: O(N) Recursive Stack
*/

#include<vector>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& nums, int sum, vector<int>& ans){
        // Base case: If we have considered all elements, add the current sum to the answer.
        if(index == nums.size()){
            ans.push_back(sum);
            return;
        }

        // Take the current element
        solve(index + 1, nums, sum + nums[index], ans);

        // Don't take the current element
        solve(index + 1, nums, sum, ans);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        solve(0, nums, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};