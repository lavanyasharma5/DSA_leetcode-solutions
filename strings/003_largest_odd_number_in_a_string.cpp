/*
problem: Largest Odd Number in a String
link: https://leetcode.com/problems/largest-odd-number-in-string/
difficulty: Easy

Description:
Given a numeric string s, return the largest odd-numbered substring.
The resulting number must not contain leading zeros.
If no odd number can be formed, return an empty string.

Approach:
1. Find the first non-zero digit to remove leading zeros.
2. Traverse from right to left and find the last odd digit.
3. If no odd digit exists, return an empty string.
4. Return the substring from the first non-zero digit to the last odd digit.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1) auxiliary space.
*/

#include<string>
using namespace std;

class Solution{
    public:
    string largestOddNumber(string num){
        int n= num.size();

        int ind1=0;
        //find the index of the first non zero digit
        while(ind1 < n && num[ind1] != '0') ind1++;

        // All zeros
        if(ind1 == n) return "";

        int ind2= -1;
        //find the last odd digit of the string from the back
        for(int i=n-1; i>= ind1; i--){
            if((num[i] - '0') % 2 == 1){
                ind2= i;
                break;
            }
        }

        //no odd digit
        if(ind2 == -1) return "";

        return num.substr(ind1, ind2 - ind1 + 1);
    } 
};