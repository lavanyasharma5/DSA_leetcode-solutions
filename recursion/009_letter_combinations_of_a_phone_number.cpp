/*
    Problem: 17. Letter Combinations of a Phone Number
    Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Difficulty: Medium

    Description:
    Given a string containing digits from 2 to 9, return all possible
    letter combinations that the number could represent based on the
    telephone keypad mapping.

    Keypad Mapping:
        2 -> abc
        3 -> def
        4 -> ghi
        5 -> jkl
        6 -> mno
        7 -> pqrs
        8 -> tuv
        9 -> wxyz

    Example:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Approach:
    1. Store the keypad mapping in a vector of strings.
    2. Use backtracking to build one letter combination at a time.
    3. For the current digit:
       - Get all letters corresponding to that digit.
       - Try each letter one by one.
    4. After choosing a letter, recursively move to the next digit.
    5. Once all digits have been processed, store the current string.
    6. Backtrack by removing the last chosen letter and try the next one.

    Why it works:
    - Every digit contributes one letter to the final string.
    - For each digit, we try every possible letter.
    - Recursion explores every possible combination.
    - Backtracking restores the previous string so other choices can
      be explored.

    Time: O(4^N)
          (Each digit has at most 4 possible letters.)

    Space: O(N)
           Recursive stack + current string
           (Excluding the output vector)
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> keypad = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(int index, string digits, string& curr, vector<string>& ans){
        //base case
        //if you reach the end of the string 
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        //get the letters corresponding to the current digits
        string letters = keypad[digits[index] - '0'];

        for(char ch: letters){
            //add the letter in the currect string we are building
            curr.push_back(ch);

            // Recursively process the next digit while keeping
            // the current letter in the combination.
            // This explores all combinations for the current digit.
            solve(index + 1, digits, curr, ans);

            //backtrack
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};

        vector<string> ans;
        string curr;

        solve(0, digits, curr, ans);

        return ans;
    }
};