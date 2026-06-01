/*
problem: Remove Outermost Parentheses
link: https://leetcode.com/problems/remove-outermost-parentheses/
difficulty: Easy

Description:
A valid parentheses string is either empty "", "(" + A + ")", or A + B,
where A and B are valid parentheses strings, and + represents string concatenation.
A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.
Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.

Approach:
- Initialize a counter to keep track of the depth of the parentheses and an empty string to build the result.
- Iterate through each character in the input string:
    - If the character is '(', increment the counter. 
      If the counter is greater than 1, append the character to the result string (this means it's not an outermost parenthesis).
    - If the character is ')', decrement the counter. 
      If the counter is greater than 0 after decrementing, append the character to the result string (this means it's not an outermost parenthesis).
- Return the resulting string after processing all characters.  

Time Complexity: O(n)
Space Complexity: O(n) for the answer, in the worst case (when all parentheses are nested).
*/

#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans= "";
        for(int i=0; i< s.length(); i++){
            if( s[i] == ')' ) count--;
            if(count > 0) ans.push_back(s[i]);
            if( s[i] == '(' ) count++;
        }
        return ans;
    }
};