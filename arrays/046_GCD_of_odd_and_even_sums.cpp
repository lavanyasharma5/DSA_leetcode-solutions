/*
    Problem: 3658. GCD of Odd and Even Sums
    Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
    Difficulty: Easy

    Description:
    Given an integer n, compute the GCD of:
    - The sum of the first n positive odd numbers.
    - The sum of the first n positive even numbers.

    Approach:
    1. Observe that the sum of the first n odd numbers is n².
    2. Observe that the sum of the first n even numbers is n(n + 1).
    3. Therefore, the answer becomes:
            GCD(n², n(n + 1))
    4. Since consecutive numbers n and (n + 1) are coprime,
       GCD(n, n + 1) = 1.
    5. Hence,
            GCD(n², n(n + 1)) = n.

    Why it works:
    - The sum of the first n odd numbers is always n².
    - The sum of the first n even numbers is always n(n + 1).
    - Factoring out n gives:
            GCD(n², n(n + 1))
          = n × GCD(n, n + 1)
    - Since consecutive integers have no common factor other than 1,
      GCD(n, n + 1) = 1.
    - Therefore, the answer is simply n.

    Time: O(1)
    Space: O(1)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};