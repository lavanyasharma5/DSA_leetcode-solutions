/*
    Problem: 39. Combination Sum
    Link: https://leetcode.com/problems/combination-sum/
    Difficulty: Medium

    Description:
    Given an array of distinct integers and a target value, return all
    unique combinations of numbers whose sum equals the target. Each
    number can be chosen an unlimited number of times. The same
    combination should not appear more than once in the answer.

    Approach:
    1. Use recursion and backtracking to explore all possible
       combinations.
    2. At every index, we have two choices:
           - Pick the current element (if it does not exceed the
             remaining target). Stay at the same index since the
             element can be reused.
           - Don't pick the current element and move to the next index.
    3. If the remaining target becomes 0, store the current
       combination as a valid answer.
    4. Backtrack by removing the last added element and continue
       exploring other possibilities.

    Why it works:
    - Staying on the same index after picking allows an element to be
      used multiple times.
    - Moving to the next index after skipping ensures that once a
      candidate is skipped, it is never considered again, preventing
      duplicate combinations such as [2,3,2] and [3,2,2].
    - Backtracking explores every valid combination while restoring
      the previous state after each recursive call.

    Time: O(2^Target) (Exponential in the worst case)
    Space: O(Target) Recursive Stack
*/

#include <vector>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& ans){

        //base case
        if(index == candidates.size()){
            if(target == 0)
                ans.push_back(curr);
            return;
        }

        if(candidates[index] <= target){
            curr.push_back(candidates[index]);

            //stay on the same index since we can use the same element in it 
            solve(index, candidates, target - candidates[index], curr, ans);

            //backtrack
            curr.pop_back();
        }

        //skip the current index, do not choose the element
        solve(index + 1, candidates, target, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);
        return ans;
    }
};