/*
    Problem: 9. Palindrome Number
    Link: https://leetcode.com/problems/palindrome-number/
    Difficulty: Easy

    Description:
    Given an integer x, determine whether it is a palindrome.
    A palindrome number reads the same forward and backward.
    Negative numbers are not considered palindromes due to
    the leading negative sign.

    Approach:
    1. If the number is negative, immediately return false.
    2. Store a copy of the original number.
    3. Reverse the digits of the number by repeatedly:
           - Extracting the last digit using x % 10.
           - Appending it to the reversed number.
           - Removing the last digit using x /= 10.
    4. Compare the reversed number with the original copy.
    5. If both are equal, the number is a palindrome;
       otherwise, it is not.

    Why it works:
    - Reversing the digits produces the number in reverse order.
    - A palindrome remains unchanged after reversing.
    - Comparing the reversed number with the original correctly
      determines whether the number is a palindrome.

    Time: O(log10 N)
    Space: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        //negative numbers are not palindrome
        if (x < 0) {
            return false;
        }

        long reverse = 0; //reverse the number
        int xcopy = x; //make a copy of x to compare later 

        //reverse the number
        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }
        //compare the reversed number with the original number
        return reverse == xcopy;        
    }
};