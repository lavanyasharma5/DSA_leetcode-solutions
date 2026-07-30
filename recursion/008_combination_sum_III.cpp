/*
    Problem: 216. Combination Sum III
    Link: https://leetcode.com/problems/combination-sum-iii/
    Difficulty: Medium

    Description:
    Find all possible combinations of exactly k numbers that add up
    to n using only numbers from 1 to 9. Each number can be used
    at most once, and duplicate combinations are not allowed.

    Approach:
    1. Use backtracking to build combinations.
    2. Start choosing numbers from 1 to 9.
    3. At each step:
       - Choose the current number.
       - Recurse with the next number (i + 1) since each number
         can only be used once.
       - Backtrack by removing the chosen number.
    4. If exactly k numbers have been chosen:
       - If the remaining target is 0, store the combination.
       - Otherwise, discard it.
    5. Stop exploring when the current number becomes greater than
       the remaining target since all later numbers will also be larger.

    Why it works:
    - Every recursive call explores one possible combination.
    - Moving to i + 1 ensures each number is used at most once.
    - Backtracking restores the previous state to explore other
      combinations.
    - The break condition prunes unnecessary recursive calls.

    Time: O(C(9, k))
          We generate all valid combinations of k numbers from 1 to 9.

    Space: O(k)
           Recursive stack + current combination
           (Excluding the output vector)
*/

#include<vector>
using namespace std;

class Solution {
public:
    void solve(int start, int k, int target, vector<int>& curr, vector<vector<int>>& ans){

        //base case
        //we have picked k numbers and the target is also 0 
        if(curr.size() == k){
            if(target == 0) ans.push_back(curr);
            return;
        }

        //use numbers from 1-9 using a for loop
        for(int i= start; i<=9; i++){
            //no point in trying and going further if the currect element is bigger than the remaining target 
            if(i > target) break;

            //choose the current number
            curr.push_back(i);
            //recursively move to the next number
            solve(i+1, k, target - i, curr, ans);
            //backtrack
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(1, k, n, curr, ans);
        return ans;
    }
};