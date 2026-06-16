/*
problem: 3612. Process string with special characters I
link: https://leetcode.com/problems/process-string-with-special-operations-i/
difficulty: medium 

Description:
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.

Approach:
1. Create an empty string res.
2. Traverse each character ch in s.
3. If ch is a lowercase letter: Append it to res.
4. f ch == '*': Remove the last character from res (if res is not empty).
5. If ch == '#': Duplicate the current string: res += res;
6. If ch == '%': Reverse the current string: reverse(res.begin(), res.end());
7. After processing all characters, return res.

Time:  O(m) where m is the length of the string 
Space: O(m)
*/

#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

class Solutions{
    public:
    string processString(string s){
        string result = "";

        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                result.push_back(ch);
            }
            else if( ch == '*'){
                if( !result.empty()){
                    result.pop_back();;
                }
            }
            else if(ch == '#'){
                result += result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};