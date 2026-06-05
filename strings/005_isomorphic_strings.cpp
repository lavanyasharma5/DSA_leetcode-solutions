/*
problem: 205. Isomorphic Strings
link: https://leetcode.com/problems/isomorphic-strings/
difficulty: Easy

Description:
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if each character in s can be mapped to exactly one character in t, and vice versa. 
The mapping must remain consistent throughout the strings
and no two different characters can map to the same character.

Approach:
1. Use two hash maps:
   - mapST to store mappings from s -> t.
   - mapTS to store mappings from t -> s.
2. Traverse both strings simultaneously.
3. If an existing mapping conflicts in either direction, return false.
    - like if a character in s is already mapped to a different character in t or
    - if a character in t is already mapped to a different character in s.
4. Otherwise, store/update the mappings.
5. If no conflicts are found, return true.

Time Complexity: O(n)
Space Complexity: O(1)   // O(k) unique characters
*/

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //stores mapping of characters s -> t
        unordered_map<char, char> mapST;
        //stores reverse mapping t -> s
        //makes sure that no two diff characters map to the same characters
        unordered_map<char, char> mapTS;

        //travserse both the strings together 
        for(int i = 0; i < s.size(); i++) {
            //store the currect characters
            char c1 = s[i];
            char c2 = t[i];

            //check if there is a conflict in the mapping
            //if c1 is already mapped to a different character than c2 or
            //if c2 is already mapped to a different character than c1
            if((mapST.count(c1) && (mapST[c1] != c2)) ||
               (mapTS.count(c2) && (mapTS[c2] != c1)) )
                return false;

            //if no conflicts then store mapping
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }
        return true; //traversed both strings without conflicts, they are isomorphic
    }
};