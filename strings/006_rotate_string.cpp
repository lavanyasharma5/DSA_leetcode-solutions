/*
problem: 796. Rotate String
link: https://leetcode.com/problems/rotate-string/
difficulty: Easy

Description:
Given two strings s and goal, return true if goal can be obtained by performing
any number of left rotations on s, otherwise return false.

A left rotation moves the first character of the string to the end.
For example:
"abcde" -> "bcdea"

Approach:
1. If the lengths of s and goal are different, return false.
2. Concatenate s with itself to form s + s.
3. All possible rotations of s appear as substrings of s + s.
4. Check if goal exists in s + s using find().
5. If found, return true; otherwise return false.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<string>
using namespace std;

class Solution {
    public:
    bool rotateString(string s, string goal){
        //if the lengths of the strings are different, they cannot be rotations of each other
        if(s.size() != goal.size()) return false;

        //concatenate s with itself. If goal is a rotation of s, it must be a substring of s+s
        string doubled= s+s;

        //check if goal is a substring of doubled
        //Find operation takes O(n) time, where n is the length of the string being searched (doubled in this case)
        return doubled.find(goal) != string::npos;
    }
};