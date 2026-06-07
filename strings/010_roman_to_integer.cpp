/*
problem: 13. Roman to Integer
link: https://leetcode.com/problems/roman-to-integer/
difficulty: Easy

Description:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Rules:
- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Approach:
1. Create a helper function value(char c) that returns the integer value of a Roman numeral character.
2. Initialize an integer variable ans to 0 to store the final result.
3. Iterate through each character in the input string s:
    - If the current character's value is less than the next character's value, subtract the
        current character's value from ans.
    - Otherwise, add the current character's value to ans.
4. Return ans as the final result.

Time Complexity: O(n), where n is the length of the input string s.
Space Complexity: O(1)
*/

#include<string>
#include<algorithm>
using namespace std;

class Solution{
    public:
    // This function returns the integer value corresponding to a Roman numeral character
    int value(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else if(c == 'M') return 1000;
        return -1; // Invalid character
    }
    int romanToInt(string s){
        int ans=0;

        for(int i=0; i< s.size(); i++){

            // If the current value is less than the next value, we subtract it from the answer
            if( i< s.size()-1 && value(s[i]) < value(s[i+1]) ){
                ans -= value(s[i]);
            }
            //current > next, we add the value to the answer
            else{
                ans += value(s[i]);
            }
        }
        return ans;
    }
};