/*
Problem: 7. Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/
Difficulty: Medium

Description:
Given a signed 32-bit integer x, reverse its digits.
If reversing the integer causes it to go outside the
32-bit signed integer range [-2^31, 2^31 - 1], return 0.

Approach:
1. Initialize ans = 0.
2. Extract the last digit of x using x % 10.
3. Remove the last digit from x using x /= 10.
4. Before appending the digit, check whether ans * 10
   would cause integer overflow or underflow.
5. If it is safe, update ans = ans * 10 + digit.
6. Repeat until x becomes 0.
7. Return the reversed integer.

Example:
Input: x = 123
Output: 321

Input: x = -120
Output: -21

Input: x = 1534236469
Output: 0

Time: O(log10 N)
Space: O(1)
*/

#include<climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            //get the last digit 
            int digit = x % 10;

            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }

            ans = ans*10 + digit; //append the digit to the reverse number
            x = x/10; // drop the last digit from x
        }
        return ans;
    }
};