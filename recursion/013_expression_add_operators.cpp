/*
Problem: 282. Expression Add Operators
Link: https://leetcode.com/problems/expression-add-operators/
Difficulty: Hard

Description:
Given a string num containing only digits and an integer target, insert
the operators '+', '-', or '*' between the digits so that the resulting
expression evaluates to target. Return all valid expressions.

Approach:
1. Use recursion + backtracking to try all possible expressions.
2. At each step, try taking one or more digits as the current number.
3. For every chosen number:
   - Try '+' and update the current value.
   - Try '-' and update the current value.
   - Try '*' while maintaining the previous number to handle
     multiplication precedence correctly.
4. Do not allow numbers with leading zeros.
5. When all digits are used:
   - If the calculated value equals target, store the expression.
   - Otherwise, discard it.

Why it works:
- Recursion explores every possible way to split the digits.
- Trying '+', '-' and '*' explores every possible operator choice.
- Backtracking allows us to try all combinations.
- The 'prev' value lets us correctly handle multiplication
  before addition/subtraction.
- The base condition stores only expressions equal to target.

Time: O(4^n)
      Each digit can lead to multiple choices of number/operator.

Space: O(n)
       Recursion stack + current expression
       (excluding the output vector).
*/

#include<vector>
#include<string>
using namespace std;

class Solution {

public:
    void solve(int index, string exp, long long value, long long prev, string& nums, int target, vector<string>& ans){
        //base case
        if(index == nums.size()){
            if(value == target)
                ans.push_back(exp);
            return;
        }

        long long curr =0;

        for(int i= index; i<nums.size(); i++){
            //dont allow nums like 05 like preceeding with 0
            if(i> index && nums[index] == '0') break;

            //get the current number
            curr = curr * 10 + (nums[i] - '0');

            //get the current part of the string
            string part = nums.substr(index, i - index + 1);

            //if index is 0 then we dont need to add any operator before the number
            if (index == 0) {
                solve(i +1, part, curr, curr, nums, target, ans);
            }
            else{
                //For subtrction -
                solve(i + 1, exp + "-" + part, value - curr, -curr, nums, target, ans);

                //For addition +
                solve(i + 1, exp + "+" + part, value + curr, curr, nums, target, ans);

                //For multiplication *
                solve(i + 1, exp + "*" + part, value - prev + prev * curr, prev * curr, nums, target, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        //index, exp so far, calculated value till now, prev value
        solve(0, "", 0, 0, num, target, ans);

        return ans;
    }
};