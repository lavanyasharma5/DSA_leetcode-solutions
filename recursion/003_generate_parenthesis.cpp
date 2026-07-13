/*
    Problem: 22. Generate Parentheses
    Link: https://leetcode.com/problems/generate-parentheses/
    Difficulty: Medium

    Description:
    Given n pairs of parentheses, generate all possible combinations
    of well-formed (valid) parentheses.

    Approach:
    1. Use recursion and backtracking to build the string one
       character at a time.
    2. Keep track of:
           open  -> number of '(' used
           close -> number of ')' used
    3. Follow two rules while building the string:
           - Add '(' only if open < n.
        if n=2, there should be at most 2 opening parentheses in the string.
           - Add ')' only if close < open.
        because there should be an opening parenthesis to match every closing parenthesis.
    4. Once the string length becomes 2 * n, store it as a valid
       combination.
    5. Backtrack by removing the last added character to explore
       other possible combinations.

    Why it works:
    - The first rule ensures we never use more than n opening
      parentheses.
    - The second rule ensures we never place a closing parenthesis
      before its matching opening parenthesis, so every generated
      string is always valid.
    - Backtracking explores all possible valid combinations without
      generating invalid ones.

    Time: O(4^N / √N)
    Space: O(N) Recursive Stack
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void solve(int n, int & open, int & close, string& curr, vector<string>& ans){
        //base case
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        //check if we can add an opening parenthesis and recurse
        if(open < n){
            curr.push_back('(');
            open ++;
            solve(n, open, close, curr, ans);
            open--;
            curr.pop_back();
        }
        //check if we can add a closing parenthesis and recurse
        if(close < open){
            curr.push_back(')');
            close ++;
            solve(n, open, close, curr, ans);
            close --;
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string curr = "";

        int open =0; //number of opening parentheses used
        int close =0; //number of closing parentheses used

        solve(n, open, close, curr, ans);

        return ans;
    }
};