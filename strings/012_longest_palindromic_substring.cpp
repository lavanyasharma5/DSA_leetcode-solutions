/*
problem: longest palindromic substring
link: https://leetcode.com/problems/longest-palindromic-substring/
difficulty: medium

description:
Given a string s, return the longest palindromic substring in s.
palindrome: a string that reads the same backward as forward.
Example 1:
Input: s = "babad"
Output: "aba"
Explanation: "aba" is also a valid answer.

Approach: Expand Around Center
1. We can iterate through each character in the string and treat it as the center of a potential palindrome.
2. For each center, we can expand outwards in both directions (left and right) to check if the characters are the same, which would indicate a palindrome.
3. We need to consider both odd-length palindromes (where the center is a single character) and even-length palindromes (where the center is between two characters).
4. As we expand, we can keep track of the longest palindrome found so far and its starting index.
5. Finally, we can return the longest palindromic substring using the starting index and length.    

Time complexity: O(n^2) - In the worst case, we might have to expand around each character and check all characters in the string.
Space complexity: O(1) - We are using only a constant amount of extra space to store the starting index and maximum length of the longest palindrome.
*/

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        // to remember the start of the longest palindromic string
        int start=0;
        //to record the length of the longest palindromic string
        int maxlen=0;

        for(int i=0; i<n; i++){
            //odd palindromic string
            int left =i; 
            int right=i;

            //keep explaing as long as 
            //left and right are within the string
            //and the left and right chars are the same
            while(left >=0 && right<n && s[left]==s[right]){
                //Check if the current palindrome is longer than the best one found so far
                if(right-left+1 > maxlen){
                    maxlen= right-left+1;
                    //Save where this palindrome starts
                    start= left;
                }
                //expand
                left--;
                right++;
            }
            
            //even palindromic string
            left = i;
            right = i+1;
            while(left >=0 && right<n && s[left]==s[right]){
                if(right-left+1 > maxlen){
                    maxlen= right-left+1;
                    start= left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxlen);
    }
};