/*
problem: 151. Reverse Words in a String
link: https://leetcode.com/problems/reverse-words-in-a-string/
difficulty: Medium

Description:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Approach:
1. Reverse the entire string to get the words in the reverse order.
2. Reverse each word in the reversed string to get the original words in the correct order.
3. Use a string to store the final answer and add each reversed word to it with a space in between.
4. Finally, remove the leading space from the answer string and return it.

Time Complexity: O(n), where n is the length of the input string s. 
Space Complexity: O(n) to store the final answer string.
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
    string reverseWords(string s) {
        int n= s.length();
        string ans= ""; // to store the final answer

        // reverse the entire string
        reverse(s.begin(), s.end()); 

        // reverse each word in the reversed string
        for(int i=0; i<n; i++){
            string word= ""; // to store the current word

            // extract the current word
            while(i<n && s[i] != ' '){
                word += s[i]; // add the current character to the word
                i++; // move to the next character
            }

            // reverse the current word to get the original word
            reverse(word.begin(), word.end());

            // add the reversed word to the answer string with a space
            if(word.length() > 0){
                ans += " " + word; // add a space before the word to separate it from the previous word
            }
        }
        return ans.substr(1); // remove the leading space from the final answer
    }
};