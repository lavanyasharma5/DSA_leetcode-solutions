/*
problem: Maximum Nesting Depth of Parentheses
link: https://leetcode.com/problems/maximum-nesting-depth-of-parentheses/
difficulty: Easy

Description:
A string is a valid parentheses string (denoted VPS) if it meets one of the following conditions:
- It is an empty string "", or a single character not equal to "(" or ")".
- It can be written as AB (A concatenated with B), where A and B are VPS's.
- It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:
- depth("") = 0
- depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
- depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
- depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
Given a VPS represented as string s, return the nesting depth of s.     

Approach:
1. Initialize two variables, depth and maxdepth, to 0.
2. Iterate through each character in the string s:
    - If the character is '(', increment the depth variable.
    - Update maxdepth to be the maximum of maxdepth and depth.
    - If the character is ')', decrement the depth variable.
3. After the loop, return maxdepth as the result.

Time Complexity: O(n), where n is the length of the string s.
Space Complexity: O(1)
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth=0; // current depth of parentheses
        int maxdepth=0; // maximum depth encountered

        for(int i=0; i<s.size(); i++){
            // If we encounter an opening parenthesis, we increase the depth
            if(s[i] == '(') depth++;

            // Update the maximum depth if the current depth is greater
            maxdepth= max(maxdepth, depth);

            // If we encounter a closing parenthesis, we decrease the depth
            // basically, it balances the opening parenthesis, so we decrease the depth
            if(s[i] == ')') depth--;
        }
        return maxdepth;
    }
};
