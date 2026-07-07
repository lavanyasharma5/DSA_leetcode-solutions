/*
    Problem: 50. Pow(x, n)
    Link: https://leetcode.com/problems/powx-n/
    Difficulty: Medium

    Description:
    Implement pow(x, n), which calculates x raised to the power n
    (i.e., xⁿ). The exponent n can be positive, negative, or zero.
    Return the result while handling negative powers efficiently.

    Approach:
    1. If the exponent is negative, convert it to a positive value
       by taking its absolute value and replace x with 1/x.
    2. If the exponent becomes 0, return 1 as the base case.
    3. If the exponent is even, recursively compute:
           (x * x)^(n / 2)
       by squaring the base and halving the exponent.
    4. If the exponent is odd, multiply one x separately and
       recursively compute:
           x * x^(n - 1)
    5. Return the final computed result.

    Why it works:
    - For even exponents:
          xⁿ = (x²)^(n/2)
      which reduces the exponent by half.
    - For odd exponents:
          xⁿ = x * xⁿ⁻¹
      making the exponent even for the next recursive step.
    - Halving the exponent whenever possible reduces the number of
      recursive calls from O(N) to O(log N).

    Time: O(log N)
    Space: O(log N) Recursive Stack
*/

#include<vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;

        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }

        if (nn == 0)
            return 1;

        if (nn % 2 == 0)
            return myPow(x * x, nn / 2);

        return x * myPow(x, nn - 1);
    }
};