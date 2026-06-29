/*
problem: 1967. Number of Strings That Appear as Substrings in Word
link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
difficulty: easy

Description:
Given an array of strings patterns and a string word,
return the number of strings in patterns that appear
as a substring of word.

Approach:
1. Initialize a counter ans = 0.
2. Traverse each string in patterns.
3. Use the built-in string function find() to check
   whether the current pattern exists inside word.
4. If the pattern is found, increment ans.
5. Return the final count.

Example:
patterns = ["a","abc","bc","d"]
word = "abc"
Checks:
"a"   -> Found
"abc" -> Found
"bc"  -> Found
"d"   -> Not Found
Answer = 3

Time: O(n × m)
       n = number of patterns
       m = length of word (find operation)
Space: O(1)
*/

#include<string>
#include<vector>
using namespace std;

class Solution{
    public:
    int numOfStrings(vector<string>& patterns, string word){
        int count=0;

        //for every string in pattern
        for(string &pattern: patterns){
            //check if the pattern exists in word using the find function
            if(word.find(patterns) != string::npos){
                count++; //founf! so increase count
            }
        }
        return count;
    }
};