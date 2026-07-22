/*
    Problem: 40. Combination Sum II
    Link: https://leetcode.com/problems/combination-sum-ii/
    Difficulty: Medium

    Description:
    Given a collection of candidate numbers (which may contain
    duplicates) and a target value, return all unique combinations
    where the chosen numbers sum to the target. Each element can be
    used only once in a combination.

    Approach:
    1. Sort the array so that duplicate elements become adjacent.
    2. Use backtracking to explore all possible combinations.
    3. At each recursion level, iterate through all remaining
       candidates using a for loop.
    4. Skip duplicate elements at the same recursion level to avoid
       generating duplicate combinations.
    5. If the current element is greater than the remaining target,
       stop exploring further since the array is sorted.
    6. Choose the current element, recurse with the next index
       (because each element can only be used once), then backtrack.

    Why it works:
    - Sorting groups duplicate values together, making them easy to
      skip.
    - The duplicate check ensures only the first occurrence of a
      value is considered at each recursion level.
    - Moving to index + 1 after choosing an element guarantees that
      each element is used at most once.
    - Backtracking explores all valid combinations while restoring
      the previous state after every recursive call.

    Time: O(2^N) * K (Worst Case) 
    Space: O(N) Recursive Stack + Current Combination
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void solve(int index, int target, vector<int>& candidates,
               vector<int>& curr, vector<vector<int>>& ans){
        // Base Case:
        // If the target becomes 0, we have found a valid combination.
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        // Try every possible element starting from the current index.
        for(int i = index; i < candidates.size(); i++){
            // Skip duplicate elements at the same recursion level.
            // This prevents duplicate combinations.
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since the array is sorted, if the current element is
            // greater than the remaining target, no further elements
            // can be chosen.
            if(candidates[i] > target)
                break;

            // Choose the current element.
            curr.push_back(candidates[i]);

            // Move to the next index because each element
            // can be used only once.
            solve(i + 1, target - candidates[i], candidates, curr, ans);

            // Backtrack: remove the last chosen element
            // to explore other possibilities.
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        // Sort the array so that:
        // 1. Duplicate elements are adjacent.
        // 2. We can stop early using the break condition.
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, target, candidates, curr, ans);

        return ans;
    }
};