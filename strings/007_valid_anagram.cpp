/*
problem: 242. Valid Anagram
link: https://leetcode.com/problems/valid-anagram/
difficulty: Easy

Description:
Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

An anagram is formed by rearranging the letters of a word using
all the original characters exactly once.

Approach:
1. If the lengths of s and t are different, return false.
2. Create a frequency array of size 26 initialized with 0.
3. Traverse both strings together:
   - Increment the count for characters in s.
   - Decrement the count for characters in t.
4. After traversal, check if all frequency values are 0.
5. If all values are 0, the strings are anagrams; otherwise return false.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }
};