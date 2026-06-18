/*
problem: 3614. Process String With Special Operations II
link: https://leetcode.com/problems/process-string-with-special-operations-ii/
difficulty: hard

Description:
You are given a string s consisting of lowercase English letters and the special characters '*', '#', and '%'.
You are also given an integer k.
The string is processed from left to right using the following rules:
1. If the character is a lowercase English letter: Append it to result.
2. If the character is '*': Remove the last character from result if it exists.
3. If the character is '#': Duplicate the current result and append it to itself.
   Example: "abc" -> "abcabc"
4. If the character is '%': Reverse the current result.
   Example: "abc" -> "cba"

After processing all characters, return the character at index k of the final result.
If k is outside the bounds of the final string, return '.'.

Important:
The final string length can become extremely large (up to 10^15), so constructing the actual string is not possible.

Approach:
1. Compute only the final length of the resulting string.
2. If k >= final length, return '.'.
3. Traverse the operations in reverse.
4. For each operation, determine where index k originated before that operation:
   - '*' : restore one removed position.
   - '#' : map k back into the first half.
   - '%' : map k to its mirrored position.
   - letter : check if this letter created position k.
5. Continue until the required character is found.
6. Return that character.

Key Idea:
Instead of building the huge string, track only:
   - current length
   - target index k
Then reverse the operations to locate the original character.

Time: O(n)
Space: O(1)
where n is the length of s.
*/

#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Step 1: compute final length
        for (char c : s) {
            if (c == '*') {
                //decrease the length but do not let it become negative 
                len = max(0LL, len - 1);
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c != '%') {
                //reversing does not chnage the  length so do nothing
                // != here means just a normal low case character 
                len++;
            }
        }

        // boundary check
        if (k >= len) return '.';

        // Step 2: backward simulation
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                len++;
            }

            else if (c == '#') {
                long long half = len / 2;

                if (k >= half) {
                    k -= half;
                }

                len = half;
            }

            else if (c == '%') {
                k = len - 1 - k;
            }

            else {
                if (k == len - 1) {
                    return c;
                }
                len--;
            }
        }
        return '.';
    }
};