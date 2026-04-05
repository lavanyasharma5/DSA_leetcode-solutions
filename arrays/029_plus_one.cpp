/*
Problem: Plus One 
link: https://leetcode.com/problems/plus-one/
Difficulty: Easy

Description:
Given an array of digits representing a non-negative integer,
increment the integer by one and return the resulting array.

Approach:
- Traverse from the end
- If digit < 9 → increment and return
- If digit == 9 → set to 0 and continue
- If all digits are 9 → insert 1 at beginning

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> plusOne(vector<int>& digits){
        int n=digits.size();
        for(int i=n-1; i>=0; i--){
            // If the current digit is less than 9, we can simply increment it and return the result
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            // If the current digit is 9, we set it to 0 
            //and continue to the next digit
            digits[i]=0;
        }
        // If all digits are 9, we need to add a new digit at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};