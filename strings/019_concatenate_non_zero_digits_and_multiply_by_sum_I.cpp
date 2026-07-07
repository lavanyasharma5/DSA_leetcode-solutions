/*
Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I
Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
Difficulty: Easy

Description:
Given an integer n, form a new number by concatenating all the
non-zero digits of n in their original order.
Compute the sum of the digits in the new number and return
the product of the new number and its digit sum.

Approach:
1. Convert the integer to a string.
2. Traverse each digit of the string.
3. Ignore digits equal to '0'.
4. Build the new number by appending each non-zero digit.
5. Simultaneously calculate the sum of the non-zero digits.
6. Return the product of the constructed number and its digit sum.

Example:
Input:
n = 10203004

Non-zero digits:
1 2 3 4
Constructed number:
1234
Digit sum:
1 + 2 + 3 + 4 = 10
Answer:
1234 * 10 = 12340

Time: O(d)
Space: O(1)
where d is the number of digits in n.
*/

#include<string>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;

        //convert number to string so that we can traverse each digit more easily
        string num = to_string(n);

        for (char digit : num) {
            if (digit != '0') {

                x = x * 10 + (digit - '0');
                sum += (digit - '0');
            }
        }
        return x * sum;
    }
};