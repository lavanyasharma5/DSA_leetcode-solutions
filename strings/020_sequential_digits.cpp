/*
    Problem: 1291. Sequential Digits
    Link: https://leetcode.com/problems/sequential-digits/
    Difficulty: Medium

    Description:
    Given two integers low and high, return all numbers within the range
    [low, high] whose digits are sequential. A sequential digit number has
    each digit exactly one greater than its previous digit.

    Approach:
    1. Store the string "123456789".
    2. Determine the number of digits in low and high.
    3. For every possible digit length:
        - Extract all substrings of that length from "123456789".
        - Convert each substring into an integer.
        - If it lies within [low, high], add it to the answer.
    4. Return the resulting list.

    Why it works:
    - Every sequential digit number is a substring of "123456789".
    - Generating all possible substrings guarantees that every valid
      sequential number is considered exactly once.
    - Filtering by the given range ensures only the required numbers
      are returned.

    Time: O(1)
    Space: O(1) (excluding the output array)
*/

#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    vector<int> sequentialDigits(int low, int high){
        //string containing all sequential digits from 1 to 9
        string digits = "123456789";

        vector<int> ans;

        //get the length of low and high to determine the range of lengths to consider
        int lowLen= to_string(low).length();
        int highLen= to_string(high).length();

        for(int len = lowLen; len <= highLen; len++){
            //generate all sequential digits of length len
            for(int start = 0; start <= 9-len; start++){
                //extract the substring of length len starting from index start
                int num = stoi(digits.substr(start, len));

                //check if the number is within the given range
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};