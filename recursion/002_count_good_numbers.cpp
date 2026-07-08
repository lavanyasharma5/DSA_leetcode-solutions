/*
    Problem: Count Good Numbers
    Link: https://takeuforward.org/plus/dsa/problems/count-good-numbers
    Difficulty: Medium

    Description:
    A digit string is considered good if every digit at an even index
    (0-based) is an even digit (0, 2, 4, 6, 8) and every digit at an
    odd index is a prime digit (2, 3, 5, 7).

    Given the length n of the string, return the total number of
    possible good digit strings. Since the answer can be very large,
    return it modulo 10^9 + 7.

    Approach:
    1. Count the number of even and odd indices:
           even = (n + 1) / 2
           odd  = n / 2
    2. Every even index has 5 possible choices.
    3. Every odd index has 4 possible choices.
    4. Compute:
           5^(even) × 4^(odd)
       using Binary Exponentiation (Fast Power) with recursion.
    5. Return the final answer modulo 10^9 + 7.

    Why it works:
    - Each even index contributes 5 independent choices.
    - Each odd index contributes 4 independent choices.
    - Multiplying these possibilities gives the total number of good
      strings.
    - Binary Exponentiation reduces exponentiation from O(N) to
      O(log N), making it efficient even for very large values of n.

    Time: O(log N)
    Space: O(log N) Recursive Stack
*/

#include<vector>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    long long findPow(long long a, long long b){
        //base case
        if(b==0) return 1;

        long long half = findPow(a, b/2);
        long long result = (half * half) % mod; //even power

        //in case of odd power
        if(b % 2 == 1) 
            result = (a * result) % mod;

        return result; //even 
    }

    int countGoodNumbers(long long n) {
        //number of even indices
        int even = (n + 1)/2;
        int odd = n/2;

        return (long long)findPow(5, even) * findPow(4, odd) % mod;
    }
};